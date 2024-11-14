#include "ModelLoader.hpp"

namespace nota {
namespace utils {

    ModelLoader::ModelLoader(std::string configFilePath)
    {
        Parse(configFilePath);
    }

    nota::app::Model ModelLoader::Load()
    {
        return nota::app::Model(m_modelPaths);
    }
    
    ///////////////////////
    // Private methods
    ///////////////////////

    void ModelLoader::Parse(std::string &configFilePath)
    {
        std::string modelPathPrefix = GetModelPathPrefix(configFilePath);
        std::ifstream configFile = OpenConfigFile(configFilePath);

        configFile >> m_numModels;
        if (m_numModels <= 0) {
            throw std::runtime_error("Invalid number of models");
        }

        std::string modelPath;
        for (int i = 0; i < m_numModels; i++)
        {
            configFile >> modelPath;
            modelPath = AddTFLiteExtensionIfNeeded(modelPath);
            m_modelPaths.push_back(modelPathPrefix + modelPath);
        }

        configFile.close();
    }

    // int ModelLoader::GetNumModels()
    // {
    //     return m_numModels;
    // }

    // std::vector<std::string> ModelLoader::GetModelPaths()
    // {
    //     return m_modelPaths;
    // }

    // std::string ModelLoader::GetModelPath(int index)
    // {
    //     return m_modelPaths[index];
    // }

    ///////////////////////
    // Private methods
    ///////////////////////

    std::ifstream ModelLoader::OpenConfigFile(std::string configFilePath)
    {
        std::ifstream configFile(configFilePath);
        if (!configFile.is_open())
        {
            std::cerr << "Failed to open config file: " << configFilePath << std::endl;
            throw std::runtime_error("Failed to open config file");
        }
        return configFile;
    }

    std::string ModelLoader::GetModelPathPrefix(std::string configFilePath)
    {
        std::string modelPathPrefix = configFilePath;
        modelPathPrefix = modelPathPrefix.substr(0, modelPathPrefix.find_last_of('/') + 1);
        return modelPathPrefix;
    }

    std::string ModelLoader::AddTFLiteExtensionIfNeeded(std::string& modelPath)
    {
        if (modelPath.find(".tflite") == std::string::npos) {
            modelPath += ".tflite";
        }
        return modelPath;
    }

    void ModelLoader::Print(std::ostream &os) const
    {
        os << "Number of models: " << m_numModels << "\n";
        os << "Model paths: " << "\n";
        for (const auto& path : m_modelPaths) {
            os << "    * " << path << "\n";
        }
    }

} // namespace utils
} // namespace nota
