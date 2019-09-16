cmake_minimum_required(VERSION 3.10)
project(open62541++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++1z -pthread -Wno-unknown-pragmas")


set(Boost_USE_STATIC_LIBS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# BOOST libs
set(BOOST_LIBRARYDIR /home/me/Projects/boost/boost_1_69_0/libs)
set (BOOST_ROOT /home/me/Projects/boost/boost_1_69_0)
find_package(Boost 1.69.0 REQUIRED COMPONENTS unit_test_framework log REQUIRED)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
endif()


find_package(open62541 REQUIRED)

#include_directories(include third-party/open62541/build/include third-party/base64/include)
include_directories(include staging/include/open62541 third-party/ostr/include third-party/flog/include)

set(
    SOURCES
    src/applicationdescription.cpp
    src/client.cpp
    src/endpointdescription.cpp
    src/expandednodeid.cpp
    src/identifier.cpp
    src/localizedtext.cpp
    src/nodeid.cpp
    src/qualifiedname.cpp
    src/referencedescription.cpp
    src/usertokenpolicy.cpp
    src/guid.cpp
    src/browserequest.cpp
    src/browsedescription.cpp
    src/browseresult.cpp
    src/browseresponse.cpp
    src/diagnosticinfo.cpp
    src/requestheader.cpp
    src/responseheader.cpp
    src/viewdescription.cpp
    src/datetime.cpp
    src/extensionobject.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC ${Boost_LIBRARIES}
    open62541
)

enable_testing()

function (make_test TEST_NAME) 
    add_executable(${TEST_NAME} test/${TEST_NAME}.cpp)

    target_link_libraries(
        ${TEST_NAME}
        ${PROJECT_NAME}
        ${Boost_LIBRARIES}
    )

    target_compile_definitions(
        ${TEST_NAME}
        PRIVATE BOOST_TEST_DYN_LINK
    )

    add_test(${TEST_NAME} ${TEST_NAME})

endfunction()

include_directories(test/include)

make_test(applicationdescription_test)
make_test(endpointdescription_test)
make_test(browsedescription_test)
make_test(browserequest_test)
make_test(browseresponse_test)
make_test(datetime_test)
make_test(diagnosticinfo_test)
make_test(expandednodeid_test)
make_test(extensionobject_test)
