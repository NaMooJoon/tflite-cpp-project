#pragma once

#include <string>
#include <tensorflow/lite/c/c_api.h>
#include <tensorflow/lite/c/common.h>
#include <tensorflow/lite/core/c/common.h>
#include <tensorflow/lite/delegates/xnnpack/xnnpack_delegate.h>
#include <tensorflow/lite/delegates/external/external_delegate.h>
// tensorflow/lite/delegates/external/external_delegate.h
#include "ExceptionHandler.hpp"

namespace nota {
namespace app {

    class TfliteNode
    {
    public:
        TfliteNode(const std::string& modelPath);
        ~TfliteNode();

    private:
        void LoadModel();

    private:
        std::string modelPath_;
        TfLiteModel* model_ = nullptr;
        TfLiteInterpreter* interpreter_ = nullptr;
        TfLiteInterpreterOptions* options_ = nullptr;
        TfLiteDelegate* xnnpackDelegate_ = nullptr;
        TfLiteDelegate* vxDelegate_ = nullptr;
        
        TfLiteTensor* inputTensor_ = nullptr;
        TfLiteTensor* outputTensor_ = nullptr;
    };

} // namespace app
} // namespace nota
