cmake_minimum_required(VERSION 3.2)
project(Demo)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Set source files
set(SOURCES
    src/main.cpp
    src/MyZRCSDKApp.cpp
)

# Add executable
add_executable(Demo ${SOURCES})

# Link directories
target_link_directories(Demo PUBLIC ${PROJECT_SOURCE_DIR}/libs)

# Set include directories
target_include_directories(Demo PUBLIC ${PROJECT_SOURCE_DIR}/)
target_include_directories(Demo PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Demo PUBLIC ${PROJECT_SOURCE_DIR}/include/libuv/include)
target_include_directories(Demo PUBLIC ${PROJECT_SOURCE_DIR}/include/include)
target_include_directories(Demo PUBLIC ${PROJECT_SOURCE_DIR}/include/include/ServiceComponents)
target_include_directories(Demo PUBLIC ${PROJECT_SOURCE_DIR}/libs)

# Link the executable with libuv
if (MSVC) # win

ADD_DEFINITIONS(-DUNICODE -D_UNICODE)

target_link_libraries(Demo
    PUBLIC
    ZRCSdk.lib
)

elseif(UNIX AND APPLE) # mac

elseif(UNIX AND NOT APPLE) # linux

target_link_libraries(Demo
    PUBLIC
    libuv.a
    atomic
    pthread
    dl
    libZRCSdk.so
)

endif()
