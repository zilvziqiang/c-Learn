cmake_minimum_required(VERSION 2.8)

#project(list Version 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O3 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


#set(MY_PROJ_SRC "../")

include_directories(../include ../utils)
aux_source_directory(./ SRC)

add_executable(local_test ${SRC}) 

#it will come to the path directory /usr/../lib/ so dangerous!!!
#set(INSTALL_DIR "../lib")
#SET(INSTALL_DIR ${PROJECT_SOURCE_DIR}/../lib)

#install(TARGETS list DESTINATION ${INSTALL_DIR})
#install(FILES ../include/list.h DESTINATION "${PROJECT_SOURCE_DIR}/../include")

