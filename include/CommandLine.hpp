#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ExceptionHandler.hpp"

namespace nota {
namespace utils {

    class CommandLine {
        private:
            const int m_argc;
            const std::string m_program_name;
            std::map<std::string, std::string> m_options;

        public:
            /**
             * @brief Constructor for CommandLine
             * @param argc Number of arguments
             * @param argv Array of arguments
             */
            CommandLine(int argc, char *argv[]);

            /**
             * @brief Get model configuration file path.
             * @return the configuration file path string.
             */
            std::string GetFilePath();
        
        private:
            CommandLine() = default; // hidden constructor

            /**
             * @brief Print the usage of the program
             */
            void PrintUsage();

            /**
             * @brief Read options from the command line arguments
             * @param argv Array of arguments
             */
            void ReadOptionsFrom(char *argv[]);
            
            /**
             * @brief Check if the argument is an option
             * @param arg Argument
             * @return True if the argument is an option, false otherwise
             */
            bool IsOption(const std::string& arg);

            /**
             * @brief Check if the option is present
             * @param name Option name
             * @return True if the option is present, false otherwise
             */
            bool HasOption(const std::string& name);

            /**
             * @brief Check if the argument has a next argument
             * @param i Argument index
             * @return True if the argument has a next argument, false otherwise
             */
            bool HasNextArgument(int i);

            /**
             * @brief Get the value of the option
             * @param name Option name
             * @return Option value
             */
            std::string GetOptionValue(const std::string& name);

            /**
             * @brief Validate the number of command line arguments
             */
            void ValidateNumOfArguments();

            /**
             * @brief Validate that the options are inputted correctly.
             */
            void ValidateOptions();
    };
}
}
