#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <thread>
#include <future>
#include <atomic>
#include <mutex>         // std::mutex, std::unique_lock
#include <cmath>
#include <random>
#include "VMD_Utils.h"


//import "C:\temp\ProTrack\VmdComWrapper\Developer Folder\Dll and h Files\VmdComWrapper.tlb" no_namespace, named_guids
#include "VmdComWrapper.h"
#include <comutil.h> // #include for _bstr_t
#ifdef DEBUG
#pragma comment(lib, "comsuppwd.lib") // link with "comsuppw.lib" (or debug version: "comsuppwd.lib")
#else
#pragma comment(lib, "comsuppw.lib") // link with "comsuppw.lib" (or debug version: "comsuppwd.lib")
#endif

bool loopRead = true;

bool timePassed(std::chrono::steady_clock::time_point last_time, float timePassedInSec)
{
    float time_sec = std::chrono::duration<double>(std::chrono::steady_clock::now() - last_time).count();
    //float miliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - last_time).count();
    //last_time = std::chrono::steady_clock::now(); -- bug 
    if (time_sec > timePassedInSec)
        return true;
    else
        return false;
}
// It makes sense only for video-Camera (not for video-File)
// To use - uncomment the following line. Optical-flow is supported only by OpenCV 3.x - 4.x
//#define TRACK_OPTFLOW
//#define GPU

// To use 3D-stereo camera ZED - uncomment the following line. ZED_SDK should be installed.
//#define ZED_STEREO


#include "yolo_v2_class.hpp"    // imported functions from DLL

#ifdef OPENCV
#ifdef ZED_STEREO
#include <sl/Camera.hpp>
#if ZED_SDK_MAJOR_VERSION == 2
#define ZED_STEREO_2_COMPAT_MODE
#endif

#undef GPU // avoid conflict with sl::MEM::GPU

#ifdef ZED_STEREO_2_COMPAT_MODE
#pragma comment(lib, "sl_core64.lib")
#pragma comment(lib, "sl_input64.lib")
#endif
#pragma comment(lib, "sl_zed64.lib")

float getMedian(std::vector<float> &v) {
    size_t n = v.size() / 2;
    std::nth_element(v.begin(), v.begin() + n, v.end());
    return v[n];
}

std::vector<bbox_t> get_3d_coordinates(std::vector<bbox_t> bbox_vect, cv::Mat xyzrgba)
{
    bool valid_measure;
    int i, j;
    const unsigned int R_max_global = 10;

    std::vector<bbox_t> bbox3d_vect;

    for (auto &cur_box : bbox_vect) {

        const unsigned int obj_size = std::min(cur_box.w, cur_box.h);
        const unsigned int R_max = std::min(R_max_global, obj_size / 2);
        int center_i = cur_box.x + cur_box.w * 0.5f, center_j = cur_box.y + cur_box.h * 0.5f;

        std::vector<float> x_vect, y_vect, z_vect;
        for (int R = 0; R < R_max; R++) {
            for (int y = -R; y <= R; y++) {
                for (int x = -R; x <= R; x++) {
                    i = center_i + x;
                    j = center_j + y;
                    sl::float4 out(NAN, NAN, NAN, NAN);
                    if (i >= 0 && i < xyzrgba.cols && j >= 0 && j < xyzrgba.rows) {
                        cv::Vec4f &elem = xyzrgba.at<cv::Vec4f>(j, i);  // x,y,z,w
                        out.x = elem[0];
                        out.y = elem[1];
                        out.z = elem[2];
                        out.w = elem[3];
                    }
                    valid_measure = std::isfinite(out.z);
                    if (valid_measure)
                    {
                        x_vect.push_back(out.x);
                        y_vect.push_back(out.y);
                        z_vect.push_back(out.z);
                    }
                }
            }
        }

        if (x_vect.size() * y_vect.size() * z_vect.size() > 0)
        {
            cur_box.x_3d = getMedian(x_vect);
            cur_box.y_3d = getMedian(y_vect);
            cur_box.z_3d = getMedian(z_vect);
        }
        else {
            cur_box.x_3d = NAN;
            cur_box.y_3d = NAN;
            cur_box.z_3d = NAN;
        }

        bbox3d_vect.emplace_back(cur_box);
    }

    return bbox3d_vect;
}

cv::Mat slMat2cvMat(sl::Mat &input) {
    int cv_type = -1; // Mapping between MAT_TYPE and CV_TYPE
    if(input.getDataType() ==
#ifdef ZED_STEREO_2_COMPAT_MODE
        sl::MAT_TYPE_32F_C4
#else
        sl::MAT_TYPE::F32_C4
#endif
        ) {
        cv_type = CV_32FC4;
    } else cv_type = CV_8UC4; // sl::Mat used are either RGBA images or XYZ (4C) point clouds
    return cv::Mat(input.getHeight(), input.getWidth(), cv_type, input.getPtr<sl::uchar1>(
#ifdef ZED_STEREO_2_COMPAT_MODE
        sl::MEM::MEM_CPU
#else
        sl::MEM::CPU
#endif
        ));
}

cv::Mat zed_capture_rgb(sl::Camera &zed) {
    sl::Mat left;
    zed.retrieveImage(left);
    cv::Mat left_rgb;
    cv::cvtColor(slMat2cvMat(left), left_rgb, CV_RGBA2RGB);
    return left_rgb;
}

cv::Mat zed_capture_3d(sl::Camera &zed) {
    sl::Mat cur_cloud;
    zed.retrieveMeasure(cur_cloud,
#ifdef ZED_STEREO_2_COMPAT_MODE
        sl::MEASURE_XYZ
#else
        sl::MEASURE::XYZ
#endif
        );
    return slMat2cvMat(cur_cloud).clone();
}

static sl::Camera zed; // ZED-camera

#else   // ZED_STEREO
std::vector<bbox_t> get_3d_coordinates(std::vector<bbox_t> bbox_vect, cv::Mat xyzrgba) {
    return bbox_vect;
}
#endif  // ZED_STEREO


#include <opencv2/opencv.hpp>            // C++
#include <opencv2/core/version.hpp>
#ifndef CV_VERSION_EPOCH     // OpenCV 3.x and 4.x
#include <opencv2/videoio/videoio.hpp>
#define OPENCV_VERSION CVAUX_STR(CV_VERSION_MAJOR)"" CVAUX_STR(CV_VERSION_MINOR)"" CVAUX_STR(CV_VERSION_REVISION)
#ifndef USE_CMAKE_LIBS
#pragma comment(lib, "opencv_world" OPENCV_VERSION ".lib")
#ifdef TRACK_OPTFLOW
/*
#pragma comment(lib, "opencv_cudaoptflow" OPENCV_VERSION ".lib")
#pragma comment(lib, "opencv_cudaimgproc" OPENCV_VERSION ".lib")
#pragma comment(lib, "opencv_core" OPENCV_VERSION ".lib")
#pragma comment(lib, "opencv_imgproc" OPENCV_VERSION ".lib")
#pragma comment(lib, "opencv_highgui" OPENCV_VERSION ".lib")
*/
#endif    // TRACK_OPTFLOW
#endif    // USE_CMAKE_LIBS
#else     // OpenCV 2.x
#define OPENCV_VERSION CVAUX_STR(CV_VERSION_EPOCH)"" CVAUX_STR(CV_VERSION_MAJOR)"" CVAUX_STR(CV_VERSION_MINOR)
#ifndef USE_CMAKE_LIBS
#pragma comment(lib, "opencv_core" OPENCV_VERSION ".lib")
#pragma comment(lib, "opencv_imgproc" OPENCV_VERSION ".lib")
#pragma comment(lib, "opencv_highgui" OPENCV_VERSION ".lib")
#pragma comment(lib, "opencv_video" OPENCV_VERSION ".lib")
#endif    // USE_CMAKE_LIBS
#endif    // CV_VERSION_EPOCH

struct vmd_detection {
    cv::Rect rect;
    int objId;
};


void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,
    int current_det_fps = -1, int current_cap_fps = -1, float fps_vmd = -1)
{
    int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };

    for (auto &i : result_vec) {
        cv::Scalar color = obj_id_to_color(i.obj_id);
        cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 1);
        if (obj_names.size() > i.obj_id) {
            auto prob = std::to_string(i.prob);
            std::string obj_name = obj_names[i.obj_id];
            if (i.track_id > 0) obj_name += "-" + std::to_string(i.track_id) + " (" + prob.substr(0, 4) + ")";
            cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, 1, 0);
            int max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
            max_width = std::max(max_width, (int)i.w + 2);
            //max_width = std::max(max_width, 283);
            std::string coords_3d;
            if (!std::isnan(i.z_3d)) {
                std::stringstream ss;
                ss << std::fixed << std::setprecision(2) << "x:" << i.x_3d << "m y:" << i.y_3d << "m z:" << i.z_3d << "m ";
                coords_3d = ss.str();
                cv::Size const text_size_3d = getTextSize(ss.str(), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, 1, 0);
                int const max_width_3d = (text_size_3d.width > i.w + 2) ? text_size_3d.width : (i.w + 2);
                if (max_width_3d > max_width) max_width = max_width_3d;
            }

            cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 15, 0)),
                cv::Point2f(std::min((int)i.x + max_width, mat_img.cols - 1), std::min((int)i.y, mat_img.rows - 1)),
                color, CV_FILLED, 8, 0);
            putText(mat_img, obj_name, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 5, 0)), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.7, cv::Scalar(0, 0, 0), 1);
            if(!coords_3d.empty()) putText(mat_img, coords_3d, cv::Point2f(i.x, i.y-1), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(0, 0, 0), 1);
        }
    }
    if (current_det_fps >= 0 && current_cap_fps >= 0) {
        std::string fps_str = "FPS detection: " + std::to_string(current_det_fps) + " FPS capture: " + std::to_string(current_cap_fps) + " fps vmd: " + std::to_string(fps_vmd).substr(0,4);
        putText(mat_img, fps_str, cv::Point2f(10, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(50, 255, 0), 2);
    }
}
//draw vmd rect and obj id
void  draw_vmd(cv::Mat mat_img, std::vector<vmd_detection> vmd_rects)
{
    for (auto vmd : vmd_rects)
    {
        cv::rectangle(mat_img, vmd.rect, cv::Scalar(0, 0, 255), 2);
        auto sObjId = std::to_string(vmd.objId);
        cv::putText(mat_img,sObjId, cv::Point(vmd.rect.x,vmd.rect.y+ vmd.rect.height-5), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(0, 0, 255), 1);
    }
    
}
#endif    // OPENCV
//coco filter - without statianary objects such as book suitcase etc.
//need to find some way to filter by diffrent datasets
std::vector<bbox_t>  filterBoxesClass(std::vector<bbox_t> boxes)
{
    std::vector<bbox_t> ret;
    for (auto &box : boxes)
    {
        if (box.obj_id <= 8 || (box.obj_id >= 14 && box.obj_id <= 23))
             ret.push_back(box);        
    }
    return ret;
      
}

void show_console_result(std::vector<bbox_t> const result_vec, std::vector<std::string> const obj_names, int frame_id = -1) {
    if (frame_id >= 0) std::cout << " Frame: " << frame_id << std::endl;
    for (auto &i : result_vec) {
        if (obj_names.size() > i.obj_id) std::cout << obj_names[i.obj_id] << " - ";
        std::cout << "obj_id = " << i.obj_id << ",  x = " << i.x << ", y = " << i.y
            << ", w = " << i.w << ", h = " << i.h
            << std::setprecision(3) << ", prob = " << i.prob << std::endl;
    }
}

std::vector<std::string> objects_names_from_file(std::string const filename) {
    std::ifstream file(filename);
    std::vector<std::string> file_lines;
    if (!file.is_open()) return file_lines;
    for(std::string line; getline(file, line);) file_lines.push_back(line);
    std::cout << "object names loaded \n";
    return file_lines;
}

template<typename T>
class send_one_replaceable_object_t {
    const bool sync;
    std::atomic<T *> a_ptr;
public:

    void send(T const& _obj) {
        T *new_ptr = new T;
        *new_ptr = _obj;
        if (sync) {// dont overwrite data until it was read
            while (a_ptr.load()) std::this_thread::sleep_for(std::chrono::milliseconds(3));   // load gets the data in the pointer, if it is not NULL, so we did not call recive to empty the pointer
        }
        std::unique_ptr<T> old_ptr(a_ptr.exchange(new_ptr));
    }

    T receive() {
        std::unique_ptr<T> ptr;
        do {
            while(!a_ptr.load()) std::this_thread::sleep_for(std::chrono::milliseconds(3));   // while no data wait, 
            ptr.reset(a_ptr.exchange(NULL));  //if there is data take it, and empty a_ptr so Send() call would store new data 
        } while (!ptr);
        T obj = *ptr;
        return obj;
    }

    bool is_object_present() {
        return (a_ptr.load() != NULL);
    }

    send_one_replaceable_object_t(bool _sync) : sync(_sync), a_ptr(NULL)
    {}
};

int main(int argc, char *argv[])
{
    //bool perform_vmd = true;
    bool display_dbg_windows = false;
    bool filter_bbox = true;
    bool vmd_draw = false;
    bool draw_only_combined = true;
    
    std::string  names_file = "data/coco.names";
    std::string  cfg_file = "cfg/yolov3.cfg";
    std::string  weights_file = "yolov3.weights";
    std ::string filename;
    std::string vmd_prm = "vmd.prm";

    if (argc > 4) {    //voc.names yolo-voc.cfg yolo-voc.weights test.mp4
        filename = argv[1];
        names_file = argv[2];
        cfg_file = argv[3];
        weights_file = argv[4];
       
    }
    else if (argc > 1) filename = argv[1];

    if (argc > 5)
        vmd_prm = argv[5];

    float const thresh = (argc > 6) ? std::stof(argv[6]) : 0.2;
   
     
    Detector detector(cfg_file, weights_file);
    //Detector detector("D:\\YOLO\\Training\\v4\\yolov4.cfg"  ,"D:\\YOLO\\Training\\v4\\yolov4.weights");
    //Detector detector2("D:\\YOLO\\Training\\v4\\yolov4.cfg", "D:\\YOLO\\Training\\v4\\yolov4.weights");
    Detector detector2(cfg_file, weights_file);

    auto obj_names = objects_names_from_file(names_file);
    std::string out_videofile = "result.avi";
    bool const save_output_videofile = false;   // true - for history
    bool const send_network = false;        // true - for remote detection
    bool const use_kalman_filter = false;   // true - for stationary camera

    bool detection_sync = true;             // true - for video-file
#ifdef TRACK_OPTFLOW    // for slow GPU
    detection_sync = false;
    Tracker_optflow tracker_flow;
    //detector.wait_stream = true;
#endif  // TRACK_OPTFLOW


    while (true)
    {
        std::cout << "input image or video filename: ";
        if(filename.size() == 0) std::cin >> filename;
        if (filename.size() == 0) break;

        try {
#ifdef OPENCV
            preview_boxes_t large_preview(100, 150, false), small_preview(50, 50, true);
            bool show_small_boxes = false;

            std::string const file_ext = filename.substr(filename.find_last_of(".") + 1);
            std::string const protocol = filename.substr(0, 7);
            if (file_ext == "avi" || file_ext == "mp4" || file_ext == "mjpg" || file_ext == "mov" ||  file_ext == "TS" || file_ext == "mkv"  || // video file
                protocol == "rtmp://" || protocol == "rtsp://" || protocol == "http://" || protocol == "https:/" ||    // video network stream
                filename == "zed_camera" || file_ext == "svo" || filename == "web_camera")   // ZED stereo camera

            {
                if (protocol == "rtsp://" || protocol == "http://" || protocol == "https:/" || filename == "zed_camera" || filename == "web_camera")
                    detection_sync = false;

                cv::Mat cur_frame;
                std::atomic<int> fps_cap_counter(0), fps_det_counter(0);
                std::atomic<int> current_fps_cap(0), current_fps_det(0);
                std::atomic<float> current_vmd_fps(0.);
                std::atomic<bool> exit_flag(false);
                std::chrono::steady_clock::time_point steady_start, steady_end;
                int video_fps = 25;
                bool use_zed_camera = false;

                track_kalman_t track_kalman;

#ifdef ZED_STEREO
                sl::InitParameters init_params;
                init_params.depth_minimum_distance = 0.5;
    #ifdef ZED_STEREO_2_COMPAT_MODE
                init_params.depth_mode = sl::DEPTH_MODE_ULTRA;
                init_params.camera_resolution = sl::RESOLUTION_HD720;// sl::RESOLUTION_HD1080, sl::RESOLUTION_HD720
                init_params.coordinate_units = sl::UNIT_METER;
                init_params.camera_buffer_count_linux = 2;
                if (file_ext == "svo") init_params.svo_input_filename.set(filename.c_str());
    #else
                init_params.depth_mode = sl::DEPTH_MODE::ULTRA;
                init_params.camera_resolution = sl::RESOLUTION::HD720;// sl::RESOLUTION::HD1080, sl::RESOLUTION::HD720
                init_params.coordinate_units = sl::UNIT::METER;
                if (file_ext == "svo") init_params.input.setFromSVOFile(filename.c_str());
    #endif
                //init_params.sdk_cuda_ctx = (CUcontext)detector.get_cuda_context();
                init_params.sdk_gpu_id = detector.cur_gpu_id;

                if (filename == "zed_camera" || file_ext == "svo") {
                    std::cout << "ZED 3D Camera " << zed.open(init_params) << std::endl;
                    if (!zed.isOpened()) {
                        std::cout << " Error: ZED Camera should be connected to USB 3.0. And ZED_SDK should be installed. \n";
                        getchar();
                        return 0;
                    }
                    cur_frame = zed_capture_rgb(zed);
                    use_zed_camera = true;
                }
#endif  // ZED_STEREO

                cv::VideoCapture cap;
                if (filename == "web_camera") {
                    cap.open(0);
                    cap >> cur_frame;
                } else if (!use_zed_camera) {
                    cap.open(filename);
                    cap >> cur_frame;
                }
#ifdef CV_VERSION_EPOCH // OpenCV 2.x
                video_fps = cap.get(CV_CAP_PROP_FPS);
#else
                video_fps = cap.get(cv::CAP_PROP_FPS);
#endif
                cv::Size const frame_size = cur_frame.size();
                //cv::Size const frame_size(cap.get(CV_CAP_PROP_FRAME_WIDTH), cap.get(CV_CAP_PROP_FRAME_HEIGHT));
                std::cout << "\n Video size: " << frame_size << std::endl;

                cv::VideoWriter output_video;
                if (save_output_videofile)
#ifdef CV_VERSION_EPOCH // OpenCV 2.x
                    output_video.open(out_videofile, CV_FOURCC('D', 'I', 'V', 'X'), std::max(35, video_fps), frame_size, true);
#else
                    output_video.open(out_videofile, cv::VideoWriter::fourcc('D', 'I', 'V', 'X'), std::max(35, video_fps), frame_size, true);
#endif

               // InitVmd();
                HRESULT hr = CoInitialize(NULL);


                ICStab *pCstab;
                ICStab2 *pCstab2;
                // HRESULT hr = S_FALSE;
                hr = CoCreateInstance(__uuidof(CStab), NULL, CLSCTX_INPROC_SERVER, __uuidof(ICStab), (void**)&pCstab);
                hr = pCstab->QueryInterface(__uuidof(ICStab2), (void**)&pCstab2);
                auto d = cur_frame.channels();
                _bstr_t prm = vmd_prm.c_str();
                pCstab->UseParamFile(prm);

               hr =  pCstab->Init2(cur_frame.cols, cur_frame.rows, 0, cur_frame.channels() * 8, 1, 0, 1, 1, 0, 0, 0);
               pCstab->InitMotionDetection();
               if (hr == S_OK)
                   std::cout << "vmd comwrapper opend with " << prm << "prm file" << std::endl;
               VMD_Utils vmdUtils(obj_names.size());
             //  pCstab->SetOpenDebugWindows(1);
               
              
                struct detection_data_t {
                    cv::Mat cap_frame;
                    std::shared_ptr<image_t> det_image;
                    std::vector<bbox_t> result_vec;
                    cv::Mat draw_frame;
                    cv::Mat draw_vmd_frame;
                    bool new_detection;
                    uint64_t frame_id;
                    bool exit_flag;
                    cv::Mat zed_cloud;
                    std::queue<cv::Mat> track_optflow_queue;
                    std::vector<vmd_detection> vmd_rects;
                    std::vector<bbox_t> additional_found_objects;
                    detection_data_t() : exit_flag(false), new_detection(false) {}
                };

                const bool sync = detection_sync; // sync data exchange
                send_one_replaceable_object_t<detection_data_t> cap2prepare(sync), cap2draw(sync),
                    prepare2detect(sync), detect2draw(sync), draw2show(sync), draw2write(sync), draw2net(sync), cap2Vmd(false), Vmd2Draw(false),
                    detect2Combine(false), vmd2Combine(false),combine2Draw(false);

                std::thread t_cap, t_prepare, t_detect, t_post, t_draw, t_write, t_network, t_vmd,t_combine;

                // capture new video-frame
                if (t_cap.joinable()) t_cap.join();
                t_cap = std::thread([&]()
                {
                    uint64_t frame_id = 0;
                    detection_data_t detection_data;
                    do {
                        detection_data = detection_data_t();
#ifdef ZED_STEREO
                        if (use_zed_camera) {
                            while (zed.grab() !=
        #ifdef ZED_STEREO_2_COMPAT_MODE
                                sl::SUCCESS
        #else
                                sl::ERROR_CODE::SUCCESS
        #endif
                                ) std::this_thread::sleep_for(std::chrono::milliseconds(2));
                            detection_data.cap_frame = zed_capture_rgb(zed);
                            detection_data.zed_cloud = zed_capture_3d(zed);
                        }
                        else
#endif   // ZED_STEREO
                        {
                            cap >> detection_data.cap_frame;
                        }
                        fps_cap_counter++;
                        detection_data.frame_id = frame_id++;
                       
                        if (detection_data.cap_frame.empty() && loopRead)
                        {
                            cap.set(cv::CAP_PROP_POS_FRAMES, 0); // rewinde video
                            detection_data.cap_frame = cv::Mat(frame_size, CV_8UC3);

                        }
                        else if (detection_data.cap_frame.empty() || exit_flag) {
                            std::cout << " exit_flag: detection_data.cap_frame.size = " << detection_data.cap_frame.size() << std::endl;
                            detection_data.exit_flag = true;
                            detection_data.cap_frame = cv::Mat(frame_size, CV_8UC3);
                        }

                        if (!detection_sync) {
                            cap2draw.send(detection_data);       // skip detection
                        }
                        cap2prepare.send(detection_data);

                        cap2Vmd.send(detection_data);

                    } while (!detection_data.exit_flag);
                    std::cout << " t_cap exit \n";
                });


                // pre-processing video frame (resize, convertion)
                t_prepare = std::thread([&]()
                {
                    std::shared_ptr<image_t> det_image;
                    detection_data_t detection_data;
                    do {
                        detection_data = cap2prepare.receive();

                        det_image = detector.mat_to_image_resize(detection_data.cap_frame);
                        detection_data.det_image = det_image;
                        prepare2detect.send(detection_data);    // detection


                    } while (!detection_data.exit_flag);
                    std::cout << " t_prepare exit \n";
                });
                //performe VMD
                //if joinable on vmd thread? if we use NectFramAsync maybe no need.
                if (t_vmd.joinable()) t_vmd.join();
                t_vmd = std::thread([&]()
                {
                    
                    detection_data_t detection_data;
                    std::default_random_engine generator;
                    std::uniform_int_distribution<int> distribution(20, 126);
                    

                    do {
                        
                     
                        detection_data = cap2Vmd.receive();

                        //if (!perform_vmd && !detection_data.exit_flag) { Sleep(5); continue; } // if not to perfome vmd, then no need to continue, and pay attention to the exit flag
                        
                        LONG res = -1;
                        int num = 0;
                        MovingObjectDataStructForIDL *vmdObjects = NULL;
                        pCstab->NextFrameWithVMDResults(detection_data.cap_frame.data, &vmdObjects,&num, &res);
                     
                        //calc VMD FPS or get fps from dll
                        float fps;
                        pCstab2->GetFPS(&fps);
                        current_vmd_fps = fps;
                        //fill rects
                        if (num > 0)
                        { 
                            for (int i = 0; i<num; i++)
                            {
                                cv::Rect rect;
                                rect.x = vmdObjects[i].left;
                                rect.y = vmdObjects[i].top;
                                rect.width = vmdObjects[i].right - vmdObjects[i].left;
                                rect.height = vmdObjects[i].bottom - vmdObjects[i].top;
                                vmd_detection detection; detection.rect = rect; detection.objId = vmdObjects[i].global_object_id;
                                detection_data.vmd_rects.push_back(detection);
                            }
                        }             
                        
                        Vmd2Draw.send(detection_data);

                        vmd2Combine.send(detection_data);

                    }while (!detection_data.exit_flag);
                    std::cout << " t_vmd exit \n";
                });
                // detection by Yolo
                if (t_detect.joinable()) t_detect.join();
                t_detect = std::thread([&]()
                {
                    std::shared_ptr<image_t> det_image;
                    detection_data_t detection_data;
                    do {
                        detection_data = prepare2detect.receive();
                        det_image = detection_data.det_image;
                        std::vector<bbox_t> result_vec;

                        if(det_image)
                            result_vec = detector.detect_resized(*det_image, frame_size.width, frame_size.height, thresh, true);  // true
                        fps_det_counter++;
                        //std::this_thread::sleep_for(std::chrono::milliseconds(150));

                        detection_data.new_detection = true;
                        detection_data.result_vec = result_vec;
                        detect2draw.send(detection_data);
                        detect2Combine.send(detection_data);
                    } while (!detection_data.exit_flag);
                    std::cout << " t_detect exit \n";
                });
                if (t_combine.joinable()) t_combine.join();
                t_combine = std::thread([&]()
                {
                    
                    /*** ideas
                        check if there is no box for last x frames. to avoid the need of reclassifing when there is only a blink in the yolo detection

                    */
                    struct tracking_info
                    {
                        int  vmdId;
                        bbox_t box;

                    };
                    detection_data_t detection_data_detect;
                    detection_data_t detection_data_vmd;
                    std::vector<tracking_info> tracking_data;
                    std::vector<vmd_detection> rects_further_analyze;
                    do
                    {
                        
                        detection_data_detect = detect2Combine.receive();
                        if(vmd2Combine.is_object_present())  //avoid deadlock on exit. reason not clear
                            detection_data_vmd = vmd2Combine.receive();
                        else {std::this_thread::sleep_for(std::chrono::milliseconds(3));  continue;  }

                        if (0)//display_dbg_windows)
                        {
                            cv::Mat detectionImg = detection_data_detect.cap_frame.clone();
                            cv::Mat vmdImg = detection_data_vmd.cap_frame.clone();
                            cv::Mat combImg = detection_data_vmd.cap_frame.clone();

                          /*  draw_boxes(detectionImg, detection_data_detect.result_vec, obj_names);
                            cv::putText(detectionImg, std::to_string(detection_data_detect.frame_id), cv::Point(0, 30), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.5, cv::Scalar(50, 50, 0), 1);

                            draw_vmd(vmdImg, detection_data_vmd.vmd_rects);
                            cv::putText(vmdImg, std::to_string(detection_data_vmd.frame_id), cv::Point(0, 30), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.5, cv::Scalar(50, 50, 0), 1);
*/
                            draw_boxes(combImg, detection_data_detect.result_vec, obj_names);
                            draw_vmd(combImg, detection_data_vmd.vmd_rects);

                           // cv::imshow("comb_detections_input", detectionImg);
                           // cv::imshow("comb_vmd_input", vmdImg);
                            cv::imshow("comb", combImg);
                        }
                        rects_further_analyze.clear();
                        //check overlap yolo and vmd, save only rects without overlap.
                        for (auto &vmd : detection_data_vmd.vmd_rects)
                        {
                            bool draw = false;
                            bool intersects = false;
                            float iou = 0.0;
                            int id = 0;
                            int detectedBox = -1;
                            for (auto &box : detection_data_detect.result_vec)
                            {
                                //check oberlap percentage of vmd on each box, and save best box
                                    //if no box, save vmd in list to further analyze
                                cv::Rect box_rect(box.x, box.y, box.w, box.h);
                                intersects = ((vmd.rect & box_rect).area() > 0);
                                if (intersects)
                                    detectedBox = id;
                                id++;
                                if (draw)
                                {
                                    auto img = detection_data_detect.cap_frame.clone();
                                    cv::rectangle(img, vmd.rect, cv::Scalar(0, 0, 255), 2);
                                    cv::rectangle(img, box_rect, cv::Scalar(255, 0, 0), 2);
                                   
                                    std::string str = intersects ? "true" : "false";
                                    cv::putText(img, str, cv::Point(0, 30), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.5, cv::Scalar(50, 50, 0), 1);

                                    imshow("intersect", img);
                                    cv::waitKey(1);

                                }

                            }
                            if (detectedBox == -1)  // there was no intercection
                            {
                                rects_further_analyze.push_back(vmd);
                            }

                        }

                        //now we have a list of vmd rects that have no intercection with darknet bbox run on cropped
                        if (0)//display_dbg_windows)
                        { //draw further to investigate vmds and the boxes we already have. to check that intersection was currect
                            cv::Mat combImg1 = detection_data_vmd.cap_frame.clone();
                            draw_boxes(combImg1, detection_data_detect.result_vec, obj_names);
                            draw_vmd(combImg1, rects_further_analyze);
                            cv::imshow("further", combImg1);
                            cv::waitKey(1);

                        }
                        //createcopy of further rects, so for each box, we would check overlap with list, maybe one box, would cover several, this would speed the process, without the need of runing detector2 several times
                       // std::vector<vmd_detection> copy_further(rects_further_analyze);
                        std::vector<int> ids_to_skip;
                        int id = 0;
                        //extract image around vmd and run detector2 on enlarged object
                       for (auto &vmd_det : rects_further_analyze )
                       {
                           auto vmd = vmd_det.rect;
                           if (std::find(ids_to_skip.begin(), ids_to_skip.end(), id) != ids_to_skip.end())
                           {
                               id++;   continue;//skip this vmd rect, it has an overlap with the box we already found
                           }
                            auto width = detection_data_vmd.cap_frame.cols;
                            auto height = detection_data_vmd.cap_frame.rows;
                            int vmd_padding = 80;  //pixels to add around vmd detection when we extract part of image
                            auto startX = std::max(0, vmd.x - vmd_padding);
                            auto startY = std::max(0, vmd.y - vmd_padding);
                            auto endX = std::min(width, vmd.x + vmd.width + vmd_padding);
                            auto endY = std::min(height, vmd.y + vmd.height + vmd_padding);
                            auto cutOutRect = cv::Rect(startX, startY, endX - startX, endY - startY);
                            if (cutOutRect.x < 0 || cutOutRect.y < 0 || cutOutRect.width < 0 || cutOutRect.height < 0)
                            {
                                printf("problem with vmd rect dimentions %d skipping\n", vmd_det.objId); 
                                continue;
                            }
                            //extract a part of full frame around vmd detection
                            cv::Mat img = detection_data_vmd.cap_frame(cutOutRect);
                            cv::Mat dst;
                            cv::resize(img,dst,cv::Size(320, 320)); // CREATE   Enlarged image to send to yolo detecton

                            //find rect on resized image
                            auto r_w = img.cols - vmd_padding;
                            auto r_h = img.rows - vmd_padding;
                            cv::Rect orig_r(vmd_padding, vmd_padding, vmd.width, vmd.height);
                            //cv::rectangle(img, orig_r, (255, 0, 0));
                            float xRatio = (float)dst.cols / img.cols;// / dst.cols;
                            float yRatio = (float)dst.rows / img.rows;// / dst.rows;
                            
                            cv::Rect vmd_on_elnlarged(vmd_padding*xRatio, vmd_padding*yRatio, vmd.width*xRatio, vmd.height*yRatio);
                            //cv::rectangle(dst, vmd_on_elnlarged, (255, 0, 0));

                            //to test -- add sharpen to image, or other image effect to see if we get better results
                            // sharpen image using "unsharp mask" algorithm
                           /* cv::MAtsharpen;
                            cv::GaussianBlur(frame, image, cv::Size(0, 0), 3);
                            cv::addWeighted(frame, 1.5, image, -0.5, 0, image); 
*/
                            bool take_all_new_bboxes = false;
                            auto boxes = detector2.detect(dst,thresh);
                            if(display_dbg_windows && boxes.size() >0)
                                draw_boxes(dst, boxes, obj_names);
                            for (auto &box : boxes)
                            {
                            //check if theres an overlap, if yes take box info
                                if ((vmd_on_elnlarged & cv::Rect(box.x, box.y, box.w, box.h)).area() > 0)
                                {
                                   // cv::rectangle(dst, vmd_on_elnlarged, cv::Scalar(222, 43, 55));

                                    cv::Rect boxOnCutout(box.x/xRatio, box.y/yRatio, box.w/xRatio, box.h/yRatio);
                                    //cv::rectangle(img, boxOnCutout, (33, 44, 230));

                                    cv::Rect boxOnOriginal(cutOutRect.x + boxOnCutout.x, cutOutRect.y + boxOnCutout.y,
                                        boxOnCutout.width, boxOnCutout.height);
                                   // cv::rectangle(detection_data_vmd.cap_frame, boxOnOriginal, (200, 200, 0));
                                    //generate results vec on full image, and (send to be drawn at end of t_combine
                                    box.x = boxOnOriginal.x;
                                    box.y = boxOnOriginal.y;
                                    box.w = boxOnOriginal.width;
                                    box.h = boxOnOriginal.height;
                                   
                                    auto track = vmdUtils.TrackObject(vmd_det.objId, box.obj_id, box.prob);
                                    
                                    box.obj_id = vmdUtils.getClass(track);
                                    detection_data_detect.additional_found_objects.push_back(box);

                                    if (display_dbg_windows)
                                    {
                                        cv::rectangle(dst, vmd_on_elnlarged, (0, 0, 255), 1);
                                    }
                                    //**follow object**
                                    // did not work well, object rect drifted fast from moving object, no Idea if it is parameters related or not.
                                    //int id = -1;
                                    //pCstab->CreateTrackingObject(vmd_det.rect.x + vmd_det.rect.width / 2, vmd_det.rect.y + vmd_det.rect.height / 2, &id);
                                    
                                    //check overlap of box, on other vmd rects waiting to be analyzed.
                                    int i = 0;
                                    for (auto &vmd : rects_further_analyze)
                                    {
                                        if ((vmd.rect & boxOnOriginal).area() > 0)
                                        {
                                            //we have intersection,
                                            if (i != id)
                                                ids_to_skip.push_back(i);
                                            
                                        }
                                        i++;
                                    }
                                }

                                else if (take_all_new_bboxes)
                                {
                                    cv::Rect boxOnCutout(box.x / xRatio, box.y / yRatio, box.w / xRatio, box.h / yRatio);
                                    //cv::rectangle(img, boxOnCutout, (33, 44, 230));

                                    cv::Rect boxOnOriginal(cutOutRect.x + boxOnCutout.x, cutOutRect.y + boxOnCutout.y,
                                        boxOnCutout.width, boxOnCutout.height);
                                    // cv::rectangle(detection_data_vmd.cap_frame, boxOnOriginal, (200, 200, 0));
                                    //generate results vec on full image, and (send to be drawn at end of t_combine
                                    box.x = boxOnOriginal.x;
                                    box.y = boxOnOriginal.y;
                                    box.w = boxOnOriginal.width;
                                    box.h = boxOnOriginal.height;
                                    detection_data_detect.additional_found_objects.push_back(box);

                                }
                            }
                            if (display_dbg_windows)
                            {
                                //cv::rectangle(dst, vmd_on_elnlarged, (0, 0, 255));
                               // imshow("full", detection_data_vmd.cap_frame);
                               // imshow("img", img);
                                imshow("crop", dst);
                                cv::waitKey(1);
                            }             
                            id++;
                        }
                       //we finished, don't save for next analize
                       detection_data_detect.vmd_rects = rects_further_analyze; // pass vmd rects that have no overlap to be displayed
                       rects_further_analyze.clear();
                       //combine2Draw - send generated results to be drawn
                       
                       combine2Draw.send(detection_data_detect);
                    }while (!detection_data_detect.exit_flag);
                    std::cout << " t_combine exit \n";
                });
                // draw rectangles (and track objects)
                t_draw = std::thread([&]()
                {
//                    int draw_option = 0; // 0 - vmd and bbox 1- only bbox 2 - only combined bbox with its vmd
                    std::queue<cv::Mat> track_optflow_queue;
                    detection_data_t detection_data;
                    std::vector<vmd_detection> old_vmd_result_vec;
                    std::vector<bbox_t> old_additional_boxes;
                    std::chrono::steady_clock::time_point last_time_vmd = std::chrono::steady_clock::now();
                    std::chrono::steady_clock::time_point last_time_combine = std::chrono::steady_clock::now();


                    do {

                        // for Video-file
                        if (detection_sync) {
                            detection_data = detect2draw.receive();
                        }
                        // for Video-camera
                        else
                        {
                            // get new Detection result if present
                            if (detect2draw.is_object_present()) {
                                cv::Mat old_cap_frame = detection_data.cap_frame;   // use old captured frame
                                detection_data = detect2draw.receive();
                                if (!old_cap_frame.empty()) detection_data.cap_frame = old_cap_frame;
                            }
                            // get new Captured frame
                            else {
                                std::vector<bbox_t> old_result_vec = detection_data.result_vec; // use old detections
                                detection_data = cap2draw.receive();
                                detection_data.result_vec = old_result_vec;
                            }
                        }
                        if (!draw_only_combined &&  Vmd2Draw.is_object_present())
                        {
                            detection_data_t vmd_detection_data;
                            vmd_detection_data = Vmd2Draw.receive();

                            detection_data.vmd_rects = vmd_detection_data.vmd_rects;

                            if (detection_data.vmd_rects.size() > 0) //save detections for smooth draw 
                            {
                                old_vmd_result_vec = detection_data.vmd_rects;
                                last_time_vmd = std::chrono::steady_clock::now();
                            }
                            else if (timePassed(last_time_vmd,1))
                            {
                                    old_vmd_result_vec.clear();
                            }
                        }
                        else if (timePassed(last_time_vmd, 1)) // no vmd remove old vmd drawing.
                        {                            
                            old_vmd_result_vec.clear();
                        }
                        
                        if (combine2Draw.is_object_present())
                        {
                            
                            //TODO
                            //1. draw only vmd from what is combined.
                            //2. option to draw added detections,
                                //3. logic of tracking, and conferming added detection. need also logic for regular detections
                            detection_data_t combined_detection_data;
                            combined_detection_data = combine2Draw.receive();
                            if(!vmd_draw) // we overwrite vmd rects and only show combined rects.
                                old_vmd_result_vec = combined_detection_data.vmd_rects;
                            if (combined_detection_data.additional_found_objects.size() > 0)
                            {
                                last_time_combine = std::chrono::steady_clock::now();
                                old_additional_boxes = combined_detection_data.additional_found_objects;

                                if (display_dbg_windows)
                                {
                                    draw_boxes(combined_detection_data.cap_frame, combined_detection_data.additional_found_objects, obj_names);
                                    imshow("combinded_added", combined_detection_data.cap_frame);
                                    cv::waitKey(1);
                                }
                            }
                            else if (timePassed(last_time_combine, 1))
                            {
                                old_additional_boxes.clear();
                            }
                            
                        }
                        else if (timePassed(last_time_combine, 1))// no new combinded remove them after time.
                        {                           
                                old_additional_boxes.clear();
                                if (draw_only_combined)
                                    old_vmd_result_vec.clear();
                        }
                        //debug draw old additional boxes, to understad what is stainig on the image.

                        //copy additional boxes to be drawn
                        //if(draw_option == x?)
                            for (auto &box : old_additional_boxes)
                            {
                                detection_data.result_vec.push_back(box);
                            }

                        cv::Mat cap_frame = detection_data.cap_frame;
                        cv::Mat draw_frame = detection_data.cap_frame.clone();
                        cv::Mat draw_vmd_frame = detection_data.cap_frame.clone();
                        std::vector<bbox_t> result_vec = detection_data.result_vec;

#ifdef TRACK_OPTFLOW
                        if (detection_data.new_detection) {
                            tracker_flow.update_tracking_flow(detection_data.cap_frame, detection_data.result_vec);
                            while (track_optflow_queue.size() > 0) {
                                draw_frame = track_optflow_queue.back();
                                result_vec = tracker_flow.tracking_flow(track_optflow_queue.front(), false);
                                track_optflow_queue.pop();
                            }
                        }
                        else {
                            track_optflow_queue.push(cap_frame);
                            result_vec = tracker_flow.tracking_flow(cap_frame, false);
                        }
                        detection_data.new_detection = true;    // to correct kalman filter
#endif //TRACK_OPTFLOW

                        // track ID by using kalman filter
                        if (use_kalman_filter) {
                            if (detection_data.new_detection) {
                                result_vec = track_kalman.correct(result_vec);
                            }
                            else {
                                result_vec = track_kalman.predict();
                            }
                        }
                        // track ID by using custom function
                        else {
                            int frame_story = std::max(5, current_fps_cap.load());
                            result_vec = detector.tracking_id(result_vec, true, frame_story, 40);
                        }

                        if (use_zed_camera && !detection_data.zed_cloud.empty()) {
                            result_vec = get_3d_coordinates(result_vec, detection_data.zed_cloud);
                        }

                        //small_preview.set(draw_frame, result_vec);
                        //large_preview.set(draw_frame, result_vec);
                        if (filter_bbox)
                        {
                            result_vec = filterBoxesClass(result_vec);
                        }

                        draw_boxes(draw_frame, result_vec, obj_names, current_fps_det, current_fps_cap, current_vmd_fps);

                        //draw frame id
                        cv::putText(draw_frame, std::to_string(detection_data.frame_id), cv::Point(0, 30), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.5, cv::Scalar(50, 50, 0), 1);

                        //draw vmd
                        if (vmd_draw && detection_data.vmd_rects.size() > 0)
                            draw_vmd(draw_frame, detection_data.vmd_rects);
                        else if (vmd_draw) // draw previos detections, so we don't have flickering of boxes.
                            draw_vmd(draw_frame, old_vmd_result_vec);
                        if (draw_only_combined)
                            draw_vmd(draw_frame, old_vmd_result_vec);
                        //show_console_result(result_vec, obj_names, detection_data.frame_id);
                        //large_preview.draw(draw_frame);
                        //small_preview.draw(draw_frame, true);

                        //draw indicators
                        std::ostringstream stringStream;
                        stringStream << "filterd:" << filter_bbox << " vmd:"<<vmd_draw<<" combine only:"<<draw_only_combined<< " debug:"<< display_dbg_windows;
                        std::string copyOfStr = stringStream.str();
                        
                        std::string guide = "f-filter, v-vmd mode , p -pause, d-debug esc -exit";
                        cv::putText(draw_frame, copyOfStr,cv::Point2f(0,draw_frame.rows - 5), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.9, cv::Scalar(0, 255,255), 1);
                        cv::putText(draw_frame, guide, cv::Point2f(draw_frame.cols/2, draw_frame.rows - 5), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.9, cv::Scalar(0, 255, 255), 1);

                        detection_data.result_vec = result_vec;
                        detection_data.draw_frame = draw_frame;
                        detection_data.draw_vmd_frame = draw_vmd_frame;
                        draw2show.send(detection_data);
                        if (send_network) draw2net.send(detection_data);
                        if (output_video.isOpened()) draw2write.send(detection_data);
                    } while (!detection_data.exit_flag);
                    std::cout << " t_draw exit \n";
                });


                // write frame to videofile
                t_write = std::thread([&]()
                {
                    if (output_video.isOpened()) {
                        detection_data_t detection_data;
                        cv::Mat output_frame;
                        do {
                            detection_data = draw2write.receive();
                            if(detection_data.draw_frame.channels() == 4) cv::cvtColor(detection_data.draw_frame, output_frame, CV_RGBA2RGB);
                            else output_frame = detection_data.draw_frame;
                            output_video << output_frame;
                        } while (!detection_data.exit_flag);
                        output_video.release();
                    }
                    std::cout << " t_write exit \n";
                });

                // send detection to the network
                t_network = std::thread([&]()
                {
                    if (send_network) {
                        detection_data_t detection_data;
                        do {
                            detection_data = draw2net.receive();

                            detector.send_json_http(detection_data.result_vec, obj_names, detection_data.frame_id, filename);

                        } while (!detection_data.exit_flag);
                    }
                    std::cout << " t_network exit \n";
                });

                cv::namedWindow("Detections", cv::WINDOW_NORMAL); // make window resizable
                // show detection
                detection_data_t detection_data;
                do {

                    steady_end = std::chrono::steady_clock::now();
                    float time_sec = std::chrono::duration<double>(steady_end - steady_start).count();
                    if (time_sec >= 1) {
                        current_fps_det = fps_det_counter.load() / time_sec;
                        current_fps_cap = fps_cap_counter.load() / time_sec;
                        steady_start = steady_end;
                        fps_det_counter = 0;
                        fps_cap_counter = 0;
                    }

                    detection_data = draw2show.receive();
                    cv::Mat draw_frame = detection_data.draw_frame;
                    cv::Mat draw_vmd_frame = detection_data.draw_vmd_frame;

                    //if (extrapolate_flag) {
                    //    cv::putText(draw_frame, "extrapolate", cv::Point2f(10, 40), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, cv::Scalar(50, 50, 0), 2);
                    //}

                    cv::imshow("Detections", draw_frame);
                   // cv::imshow("vmd ", draw_vmd_frame);
                    int key = cv::waitKey(3);    // 3 or 16ms
                    if (key == 'f') show_small_boxes = !show_small_boxes;
                    if (key == 'd')  display_dbg_windows = !display_dbg_windows;
                    if (key == 'f')  filter_bbox = !filter_bbox;
                    if (key == 'v') {
                        vmd_draw = !vmd_draw;
                        draw_only_combined = !draw_only_combined;
                    }
                    if (key == 'p') while (true) if (cv::waitKey(100) == 'p') break;
                    //if (key == 'e') extrapolate_flag = !extrapolate_flag;
                    if (key == 27) { exit_flag = true;}

                    //std::cout << " current_fps_det = " << current_fps_det << ", current_fps_cap = " << current_fps_cap << std::endl;
                } while (!detection_data.exit_flag);
                std::cout << " show detection exit \n";

                cv::destroyWindow("window name");
                // wait for all threads+
                if (t_combine.joinable()) t_combine.join();
                if (t_cap.joinable()) t_cap.join();
                if (t_prepare.joinable()) t_prepare.join();
                if (t_detect.joinable()) t_detect.join();
                if (t_vmd.joinable())
                    t_vmd.join();
               
                if (t_post.joinable()) t_post.join();
                if (t_draw.joinable()) t_draw.join();
                if (t_write.joinable()) t_write.join();
                if (t_network.joinable()) t_network.join();
               

                break;

            }
            else if (file_ext == "txt") {    // list of image files
                std::ifstream file(filename);
                if (!file.is_open()) std::cout << "File not found! \n";
                else
                    for (std::string line; file >> line;) {
                        std::cout << line << std::endl;
                        cv::Mat mat_img = cv::imread(line);
                        std::vector<bbox_t> result_vec = detector.detect(mat_img);
                        show_console_result(result_vec, obj_names);
                        //draw_boxes(mat_img, result_vec, obj_names);
                        //cv::imwrite("res_" + line, mat_img);
                    }

            }
            else {    // image file
                // to achive high performance for multiple images do these 2 lines in another thread
                cv::Mat mat_img = cv::imread(filename);
                auto det_image = detector.mat_to_image_resize(mat_img);

                auto start = std::chrono::steady_clock::now();
                std::vector<bbox_t> result_vec = detector.detect_resized(*det_image, mat_img.size().width, mat_img.size().height);
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<double> spent = end - start;
                std::cout << " Time: " << spent.count() << " sec \n";

                //result_vec = detector.tracking_id(result_vec);    // comment it - if track_id is not required
                draw_boxes(mat_img, result_vec, obj_names);
                cv::imshow("window name", mat_img);
                show_console_result(result_vec, obj_names);
                cv::waitKey(0);
            }
#else   // OPENCV
            //std::vector<bbox_t> result_vec = detector.detect(filename);

            auto img = detector.load_image(filename);
            std::vector<bbox_t> result_vec = detector.detect(img);
            detector.free_image(img);
            show_console_result(result_vec, obj_names);
#endif  // OPENCV
        }
        catch (std::exception &e) { std::cerr << "exception: " << e.what() << "\n"; getchar(); }
        catch (...) { std::cerr << "unknown exception \n"; getchar(); }
        filename.clear();
    }

    return 0;
}
