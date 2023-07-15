//
// Created by Minas Worku on 7/14/23.
//

#include "InitializeProject.hpp"



void InitializeProject::configure_project() {
    if (!std::filesystem::is_directory(project_location)) {
        print_error(project_name + " is not a directory.");
        return;
    }

    if (std::filesystem::exists(project_location)) {
        std::string project_path = project_location + "/" + project_name;
        if (std::filesystem::exists(project_path)) {
            print_error(project_name + " already exists in " + project_location + ".");
            return;
        } else {
            const bool created = std::filesystem::create_directory(project_path);
            if (created) {
                std::time_t now = std::time(nullptr);
                std::tm* timeinfo = std::localtime(&now);
                int currentYear = timeinfo->tm_year + 1900;

                print_progress("Creating the biton configuration file...");

                std::ofstream file;
                file.open(project_path + "/babylon.toml");
                if (!file.is_open()) {
                    print_error("Failed to create the file.");
                    return;
                }
                file << "[[package]]\n";
                file << "name = \"" + project_name + "\"\n";
                file << "version = \"0.1.0\"\n";
                file << "edition = \"" + std::to_string(currentYear) + "\"\n";
                file.close();
                create_source_directory();

                print_progress("Configuration file created successfully.");

            }
        }
    } else {
        print_error(project_location + " doesn't exist in your system.");

        return;
    }
}

void InitializeProject::create_source_directory() {
    const std::string project_path = project_location+'/'+project_name;
    const std::string src_dir = project_path+"/src";
    const bool created = std::filesystem::create_directory(src_dir);
   if(created){
       std::ofstream file;
       file.open(src_dir + "/main.bit");
       if (!file.is_open()) {
           print_error("Failed to create the main.bit file.");
           return;
       }
       file << "fun main() {\n";
       file << "#Your code goes here.😎\n";
       file << '}';
       file.close();
   }
}
