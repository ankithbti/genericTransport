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
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES
	    src/Main.cpp
        src/PBProtocol.cpp
        src/PBSchemaAdaptor.cpp
        src/TcpClientConnection.cpp
        src/TcpConnectionManager.cpp
        src/TcpServerTransport.cpp)

## To make a real file from template using replacing some @TAG@
#configure_file(
#        "${PROJECT_SOURCE_DIR}/main.cpp.in"
#        "${PROJECT_SOURCE_DIR}/main.cpp"
#)

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

#link_libraries(genericTransport ${BOOST_INSTALL_ROOT}/lib/libboost_filesystem.so)
#link_libraries(genericTransport ${BOOST_INSTALL_ROOT}/lib/libboost_system.so)
#link_libraries(genericTransport ${BOOST_INSTALL_ROOT}/lib/libboost_thread.so)
#link_libraries(genericTransport ${BOOST_INSTALL_ROOT}/lib/libboost_regex.so)


target_link_libraries(genericTransport boost_system)
target_link_libraries(genericTransport boost_thread)
target_link_libraries(genericTransport pthread)
target_link_libraries(genericTransport protobuf)

ADD_CUSTOM_COMMAND(OUTPUT generateProtoSource.out
        COMMAND ${PROTOBUF_ROOT}/bin/protoc -I=${CMAKE_SOURCE_DIR} --cpp_out=${CMAKE_SOURCE_DIR}/protoCppStore ${CMAKE_SOURCE_DIR}/protoFiles/${PROTOBUF_FILE_NAME}
        DEPENDS ${CMAKE_SOURCE_DIR}/protoFiles
        )

add_custom_target( generateProtoSourceTarget ALL
        DEPENDS generateProtoSource.out
        )

## If to use a Makefile which has logic of building something
#add_custom_target(mytest COMMAND make -C ${mytest_SOURCE_DIR}
#        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

add_dependencies(genericTransport generateProtoSourceTarget)
