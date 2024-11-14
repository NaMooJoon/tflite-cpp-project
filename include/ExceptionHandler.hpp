#pragma once

#include <exception>
#include <iostream>

inline void HandleException(const std::exception& e)
{
    std::cerr << "Exception: " << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
}

inline void HandleErrorMessage(const std::string& errorMessage)
{
    std::cerr << "Error: " << errorMessage << std::endl;
    std::exit(EXIT_FAILURE);
}
