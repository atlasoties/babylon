//
// Created by Minas Worku on 7/15/23.
//

#ifndef BABYLON_ERROR_H
#define BABYLON_ERROR_H
#include <iostream>

// Terminal color codes
const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string RESET = "\033[0m";
struct Error {
    void static print_error(const std::string& message) {
        std::cerr << RED << "[Error] " << message << RESET << std::endl;
    }

    void static print_progress(const std::string& message) {
        std::cout << GREEN << "[Progress] " << message << RESET << std::endl;
    }
};


#endif //BABYLON_ERROR_H
