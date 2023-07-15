//
// Created by Minas Worku on 7/14/23.
//

#ifndef BABYLON_INITIALIZEPROJECT_HPP
#define BABYLON_INITIALIZEPROJECT_HPP

#include <string>
#include <utility>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
#include "../error/Error.h"
struct InitializeProject : public Error{
    explicit InitializeProject(std::string  project_name,std::string project_location = "."): project_location{std::move(project_location)}, project_name{std::move(project_name)}
    {
//        configure_project();
    }
    void configure_project();
    void create_source_directory();
private:
    std::string project_location;
    std::string project_name;
};


#endif //BABYLON_INITIALIZEPROJECT_HPP
