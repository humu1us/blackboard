cmake_minimum_required(VERSION 3.5.1)

project(blackboard CXX)

file(GLOB MAIN_SRC src/*.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (${CMAKE_BUILD_TYPE} AND ${CMAKE_BUILD_TYPE} EQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

add_executable(${PROJECT_NAME} ${MAIN_SRC})
