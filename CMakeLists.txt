cmake_minimum_required(VERSION 3.3)
project(genericTransport)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)

if( DEFINED ENV{PROTOBUF_ROOT} )
    set(PROTOBUF_ROOT $ENV{PROTOBUF_ROOT})
else()
    message(FATAL_ERROR " PROTOBUF_ROOT not set in env. ")
endif()

if( DEFINED ENV{BOOST_INSTALL_ROOT} )
    set(BOOST_INSTALL_ROOT $ENV{BOOST_INSTALL_ROOT})
else()
    message(FATAL_ERROR " BOOST_INSTALL_ROOT not set in env. ")
endif()


set(PROTOBUF_FILE_NAME genericTransport.proto)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/PBProtocol.cpp)

configure_file(
        "${PROJECT_SOURCE_DIR}/main.cpp.in"
        "${PROJECT_SOURCE_DIR}/main.cpp"
)

INCLUDE_DIRECTORIES( "${CMAKE_SOURCE_DIR}" )
INCLUDE_DIRECTORIES( "${CMAKE_SOURCE_DIR}/include" )
INCLUDE_DIRECTORIES( "${PROTOBUF_ROOT}/include" )
INCLUDE_DIRECTORIES( "${BOOST_INSTALL_ROOT}/include" )
INCLUDE_DIRECTORIES( "${CMAKE_SOURCE_DIR}/include" )

LINK_DIRECTORIES(
        ${PROTOBUF_ROOT}/lib
        ${BOOST_INSTALL_ROOT}/lib
)

add_executable(genericTransport ${SOURCE_FILES})

link_libraries(genericTransport ${BOOST_INSTALL_ROOT}/lib/libboost_filesystem.so)
link_libraries(genericTransport ${BOOST_INSTALL_ROOT}/lib/libboost_system.so)
link_libraries(genericTransport ${BOOST_INSTALL_ROOT}/lib/libboost_thread.so)
link_libraries(genericTransport ${BOOST_INSTALL_ROOT}/lib/libboost_regex.so)

target_link_libraries(genericTransport protobuf)
target_link_libraries(genericTransport pthread)

ADD_CUSTOM_COMMAND(OUTPUT generateProtoSource.out
        COMMAND ${PROTOBUF_ROOT}/bin/protoc -I=${CMAKE_SOURCE_DIR} --cpp_out=${CMAKE_SOURCE_DIR}/protoCppStore ${CMAKE_SOURCE_DIR}/protoFiles/${PROTOBUF_FILE_NAME}
        DEPENDS ${CMAKE_SOURCE_DIR}/protoFiles
        )

add_custom_target( generateProtoSourceTarget ALL
        DEPENDS generateProtoSource.out
        )

add_dependencies(genericTransport generateProtoSourceTarget)