cmake_minimum_required(VERSION 3.20)

project(EmbeddedDeviceReliabilityPlatform
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(device_sim
    src/main.cpp
)

add_executable(device_tests
    tests/test_main.cpp 
    src/Battery.cpp
    src/Charger.cpp
    src/Motor.cpp
)

#Tells CMake whree compiler should look for header files when compiling a certain target
target_include_directories(device_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)