#include "Model.hpp"

namespace nota {
namespace app {

    Model::Model(const std::vector<std::string> &modelPaths)
    {
        for (const auto& modelPath : modelPaths) {
            nodes.push_back(std::make_unique<TfliteNode>(modelPath));
        }
    }

    void Model::SetInput(cv::Mat &image)
    {
    }
    void Model::DoInference()
    {
    }
    void Model::GetOutput(cv::Mat &output)
    {
    }
} // namespace app
} // namespace nota