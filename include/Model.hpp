#pragma once

#include <vector>
#include <string>
#include <memory>
#include <opencv2/opencv.hpp>
#include <tensorflow/lite/c/c_api.h>

#include "TfliteNode.hpp"


namespace nota {
namespace app {

    using TfliteNodeRef = std::unique_ptr<TfliteNode>;

    class Model
    {
    public:
        Model(const std::vector<std::string>& modelPaths);

        void SetInput(cv::Mat& image);
        void DoInference();
        void GetOutput(cv::Mat& output);
    private:
        Model() = default; // hidden constructor
        
        std::vector<TfliteNodeRef> nodes;
    
    };
    


} // namespace app
} // namespace nota