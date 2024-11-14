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
    return EXIT_SUCCESS;
}
