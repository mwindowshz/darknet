#pragma once
#include <unordered_map>
#include <algorithm>
class VMD_Utils
{
	struct tracking_info
	{
		int vmd_obj_id;
        int times;
		std::vector<float> classification_scores;
		std::vector<int> classification_times;
		tracking_info() {};
		tracking_info(int numOfClasses)
		{
			vmd_obj_id = -1;
            times = 0;
			classification_scores.resize(numOfClasses);
			classification_times.resize(numOfClasses);// = new int[numOfClasses];
            //ZeroMemory(classification_scores,)
		}
	};
public:
	VMD_Utils(int numOfClasses) {
		_numOfClasses = numOfClasses;
	}
	~VMD_Utils() {};

	int _numOfClasses;
	std::unordered_map<int,tracking_info> _trackingInfo;
	tracking_info TrackObject(int vmdId, int classificationId, float score)
	{
		//tracking_info *info = nullptr;
		//auto info = _trackingInfo.find(vmdID);
		//auto info  = _trackingInfo.find(vmdId)->second;
		if(_trackingInfo.find(vmdId)==_trackingInfo.end())
		//if (_trackingInfo[vmdId] == nullptr)
		{
			tracking_info i(_numOfClasses);
			i.vmd_obj_id = vmdId;
            i.times = 1;
			//i.classification_scores = new float[_numOfClasses];
			i.classification_scores[classificationId] += score;
			i.classification_times[classificationId] += 1;
			_trackingInfo[vmdId] = i;
			return i;
		}
		
        _trackingInfo[vmdId].classification_scores[classificationId] += score;
        _trackingInfo[vmdId].classification_times[classificationId] += 1;
        _trackingInfo[vmdId].times += 1;
        auto info = _trackingInfo[vmdId];
		return info;
	}
    int getClass(tracking_info info)
    {
        //min number of classification
        //highest number of classification for a class
        //highest score for classification calss
        auto times_classifed = info.times;
        auto highScore = std::max_element(info.classification_scores.begin(), info.classification_scores.end());
        auto hightimes = std::max_element(info.classification_times.begin(), info.classification_times.end());
        //add some logic if needed

        
       int classid = std::distance(info.classification_scores.begin(),highScore);
        return classid;// classid;
    }
};

