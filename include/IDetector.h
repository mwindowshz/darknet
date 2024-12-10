#pragma once

/*struct bbox_t {
	unsigned int x, y, w, h;	// (x,y) - top-left corner, (w, h) - width & height of bounded box
	float prob;					// confidence - probability that the object was found correctly
	unsigned int obj_id;		// class of object - from range [0, classes-1]
	unsigned int track_id;		// tracking id for video (0 - untracked, 1 - inf - tracked object)
};

struct image_t {
	int h;						// height
	int w;						// width
	int c;						// number of chanels (3 - for RGB)
	float *data;				// pointer to the image data
};*/

struct bbox_t {
	unsigned int x, y, w, h;	// (x,y) - top-left corner, (w, h) - width & height of bounded box
	float prob;					// confidence - probability that the object was found correctly
	unsigned int obj_id;		// class of object - from range [0, classes-1]
	unsigned int track_id;		// tracking id for video (0 - untracked, 1 - inf - tracked object)
	unsigned int frames_counter;// counter of frames on which the object was detected
	float x_3d, y_3d, z_3d;        // center of object (in Meters) if ZED 3D Camera is used
};

struct image_t {
	int h;						// height
	int w;						// width
	int c;						// number of chanels (3 - for RGB)
	float* data;				// pointer to the image data
};

class IDetector
{
public:
	virtual std::vector<bbox_t> detect(image_t img, float thresh = 0.2, bool use_mean = false) = 0;
	virtual int detectResArray(image_t img, float thresh = 0.2, bool use_mean = false, bbox_t** pBoxes = NULL) = 0;
	//virtual int detect_resized_ResArray(image_t img, int init_w, int init_h, float thresh = 0.2, bool use_mean = false, bbox_t** pBoxes = NULL) { return 0; }
	//virtual int tracking_id_array(bbox_t** pBoxes, int numOfBoxes, bool const change_history = true, int const frames_story = 10, int const max_dist = 150)=0;
	virtual int get_net_width() const = 0;
	virtual int get_net_height() const = 0;
};

extern "C" __declspec(dllexport) IDetector* GetDetectorPtr(const char* cfgFile, const char* weightsFile);
extern "C" __declspec(dllexport) IDetector* GetDetectorPtr2(const char* cfgFile, const char* weightsFile);
