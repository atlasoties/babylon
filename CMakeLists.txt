cmake_minimum_required(VERSION 3.25)
project(babylon)

set(CMAKE_CXX_STANDARD 17)


include_directories(third-party/cxxopts/include)
include_directories(third-party/indicators/include)  # Adjust the path to the indicators library

add_executable(babylon
        src/main.cpp
        init/InitializeProject.hpp
        init/InitializeProject.cpp
        build/Build.cpp
        build/Build.hpp
        run/Run.cpp
        run/Run.h
        clean/Clean.cpp
        clean/Clean.h
        install/Install.cpp
        install/Install.h
        update/Update.cpp
        update/Update.h

        error/Error.h
        error/Error.cpp)

target_link_libraries(babylon PRIVATE cxxopts)

