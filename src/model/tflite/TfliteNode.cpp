#include "TfliteNode.hpp"

namespace nota {
namespace app {

    TfliteNode::TfliteNode(const std::string &modelPath)
        : modelPath_(modelPath)
    {
        LoadModel();
    }

    TfliteNode::~TfliteNode()
    {
        if (interpreter_ != nullptr) {
            TfLiteInterpreterDelete(interpreter_);
        }
        if (xnnpackDelegate_ != nullptr) {
            TfLiteXNNPackDelegateDelete(xnnpackDelegate_);
        }
        if (vxDelegate_ != nullptr) {
            // TfLiteExternalDelegateDelete(vxDelegate_);
        }
        if (options_ != nullptr) {
            TfLiteInterpreterOptionsDelete(options_);
        }
    }

    void TfliteNode::LoadModel()
    {
        model_ = TfLiteModelCreateFromFile(modelPath_.c_str());
        if (model_ == nullptr) {
            HandleErrorMessage("Failed to load model from " + modelPath_);
        }

        options_ = TfLiteInterpreterOptionsCreate();

        // XNNPack delegate
        xnnpackDelegate_ = TfLiteXNNPackDelegateCreate(nullptr);
        if (xnnpackDelegate_ == nullptr) {
            HandleErrorMessage("Failed to create XNNPack delegate");
        }
        TfLiteInterpreterOptionsAddDelegate(options_, xnnpackDelegate_);
        
        // VX delegate
        // const char* delegate_path = "/home/torizon/lib/tflite-vx-delegate/build/libvx_delegate.so";
        // TfLiteExternalDelegateOptions vx_delegate_options  = TfLiteExternalDelegateOptionsDefault(delegate_path);
        // vxDelegate_ = TfLiteExternalDelegateCreate(&vx_delegate_options);
        // if (vxDelegate_ == nullptr) {
        //     HandleErrorMessage("Failed to create VX delegate");
        // }
        // TfLiteInterpreterOptionsAddDelegate(options_, vxDelegate_);

        // Interpreter
        interpreter_ = TfLiteInterpreterCreate(model_, options_);
        if (interpreter_ == nullptr) {
            HandleErrorMessage("Failed to create interpreter");
        }
 
    }
} // namespace app
} // namespace nota