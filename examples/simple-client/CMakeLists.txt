cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(example-client)

include_directories(../../include)
include_directories(../../third-party/open62541/include)
include_directories(../../third-party/base64/include)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/../../build/libopen62541-cpp-wrapper.so)
