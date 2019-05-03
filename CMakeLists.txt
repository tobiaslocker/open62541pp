cmake_minimum_required(VERSION 3.10)
project(open62541-cpp-wrapper)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++14 -pthread -Wno-unknown-pragmas")

find_package(open62541 REQUIRED COMPONENTS FullNamespace Discovery)

#set(Boost_USE_STATIC_LIBS ON)

# BOOST libs
set(BOOST_LIBRARYDIR /home/me/Projects/boost/boost_1_69_0/libs)
set (BOOST_ROOT /home/me/Projects/boost/boost_1_69_0)
find_package(Boost 1.69.0 REQUIRED COMPONENTS unit_test_framework log REQUIRED)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
endif()

include_directories(include)
set(SOURCES src/open62541.cpp src/log.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC ${Boost_LIBRARIES}
    open62541
)

enable_testing()

add_executable(unit-tests test/unit-tests.cpp)

target_link_libraries(
    unit-tests
    ${PROJECT_NAME}
    ${Boost_LIBRARIES}
)

target_compile_definitions(
    unit-tests
    PRIVATE BOOST_TEST_DYN_LINK
)

add_test(all unit-tests)
