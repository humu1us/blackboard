cmake_minimum_required(VERSION 3.5.1)

project(blackboard CXX)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(QALCULATE libqalculate)

file(GLOB MAIN_SRC src/*.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (${CMAKE_BUILD_TYPE} AND ${CMAKE_BUILD_TYPE} EQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${QALCULATE_INCLUDE_DIRS})

link_directories(${GTKMM_LIBRARY_DIRS})
link_directories(${QALCULATE__LIBRARY_DIRS})


add_executable(${PROJECT_NAME} ${MAIN_SRC})

target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${QALCULATE_LIBRARIES})
