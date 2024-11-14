#include "CommandLine.hpp"

namespace nota {
namespace utils {

    CommandLine::CommandLine(int argc, char *argv[])
        : m_argc(argc), m_program_name(argv[0])
    {
        ValidateNumOfArguments();
        ReadOptionsFrom(argv);
        ValidateOptions();
    }

    std::string CommandLine::GetFilePath()
    {
        return GetOptionValue("-f");
    }

    ///////////////////////
    // Private methods
    ///////////////////////
    
    void CommandLine::PrintUsage()
    {
        std::cout << "Usage: " << m_program_name << " -f <config_file>" << std::endl;
        std::cout << "Options:\n"
                  << "  -f <config_file>  Specify the configuration file (required)\n"
                  << "  -h                Display this help message\n";
    }

    void CommandLine::ReadOptionsFrom(char *argv[])
    {
        for (int i = 1; i < m_argc; ++i) {

            std::string arg = argv[i];
            if (IsOption(arg)) {

                if (HasNextArgument(i) && !(IsOption(argv[i + 1]))) {
                    m_options[arg] = argv[i + 1];
                    i++;
                } else {
                    m_options[arg] = "";
                }

            }
        }
    }

    bool CommandLine::IsOption(const std::string &arg)
    {
        return arg[0] == '-';
    }

    bool CommandLine::HasOption(const std::string &name)
    {
        return m_options.find(name) != m_options.end();
    }

    bool CommandLine::HasNextArgument(int i)
    {
        return i + 1 < m_argc;
    }

    std::string CommandLine::GetOptionValue(const std::string &name)
    {
        return m_options[name];
    }

    void CommandLine::ValidateNumOfArguments()
    {
        if (m_argc < 2) {
            PrintUsage();
            std::exit(EXIT_SUCCESS);
        }
    }

    void CommandLine::ValidateOptions()
    {
        if (HasOption("-h")) {
            PrintUsage();
            std::exit(EXIT_SUCCESS);
        }

        if (!HasOption("-f")) {
            HandleErrorMessage("Missing required option -f <config_file>");
        }
    }

}
}
