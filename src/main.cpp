#include <iostream>
#include "../init/InitializeProject.hpp"
#include "../build/Build.hpp"
#include "../run/Run.h"
#include "../clean/Clean.h"
#include "../install/Install.h"
#include "../update/Update.h"
#include <cxxopts.hpp>

int main(int argc, char* argv[]) {
    cxxopts::Options options("babylon", "Command-line tool for babylon");

    options.add_options()
            ("command", "Command to execute", cxxopts::value<std::string>())
            ("release", "Build in release mode")
            ("debug", "Build in debug mode")
            ;

    options.positional_help("Command");
    options.parse_positional({"command"});

    auto result = options.parse(argc, argv);

    if (result.count("command")) {
        std::string command = result["command"].as<std::string>();

        if (command == "new") {
            if (result.count("release") || result.count("debug")) {
                Error::print_error("Invalid usage: 'new' command does not support release or debug mode.");
            } else if (result.count("release") && result.count("debug")) {
                Error::print_error("Invalid usage: Cannot specify both release and debug mode for 'new' command.");
            } else if (result.count("debug")) {
                Error::print_error("Invalid usage: 'new' command does not support debug mode." );
            } else {
                std::string projectName = result["release"].as<std::string>();
                InitializeProject project(projectName);
            }
        } else if (command == "build") {
            bool releaseMode = result.count("release") > 0;
            bool debugMode = result.count("debug") > 0;

            if (releaseMode && debugMode) {
                Error::print_error("Invalid usage: Cannot specify both release and debug mode for 'build' command." );
            } else {
                Build build(releaseMode);
            }
        } else if (command == "install") {
            Install install;
        } else if (command == "update") {
            Update update;
        } else if (command == "run") {
            Run run;
        } else if (command == "clean") {
            Clean clean;
        } else {
            Error::print_error( "Unknown command: "+ command );
        }
    } else {
        Error::print_error( "No command specified." );
    }

    return 0;
}

