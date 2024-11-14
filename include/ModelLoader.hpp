#pragma once

#include <fstream>

#include "Model.hpp"

namespace nota {
namespace utils {

    class ModelLoader {
    public:
        ModelLoader(std::string configFilePath);
        nota::app::Model Load();
    private:
        ModelLoader(); // hidden constructor
        void Parse(std::string& configFilePath);

        std::ifstream OpenConfigFile(std::string configFilePath);
        std::string GetModelPathPrefix(std::string configFilePath);
        std::string AddTFLiteExtensionIfNeeded(std::string &modelPath);

        void Print(std::ostream& os) const;
    private:
        int m_numModels;
        std::vector<std::string> m_modelPaths;
    };
    


} // namespace utils
} // namespace nota
