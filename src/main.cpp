#include <iostream>
#include <stdexcept>
#include <string>
#include <opencv2/core.hpp>

#include "CommandLine.hpp"
#include "ModelLoader.hpp"
#include "Model.hpp"

using namespace nota::utils;

int main(int argc, char* argv[]) 
{
    CommandLine cmd(argc, argv);
    ModelLoader modelLoader(cmd.GetFilePath());

    auto model = modelLoader.Load();
    std::cout << "Model loaded" << std::endl;

    return EXIT_SUCCESS;
}
