cmake_minimum_required(VERSION 3.16)

project(zr-controller-api)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(/usr/local/include)
include_directories(/app/zoom-sdk/include)
link_directories(/app/zoom-sdk/lib)


add_executable(zr-controller-api main.cpp)
target_link_libraries(zr-controller-api ZRCSdk)
