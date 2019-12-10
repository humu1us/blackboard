cmake_minimum_required(VERSION 3.5.1)

project(blackboard CXX)

find_package(PkgConfig REQUIRED)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    MESSAGE("!! Compiling with debug symbols")
endif()

pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(QALCULATE libqalculate)

file(GLOB MAIN_SRC src/*.cc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall)

include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${QALCULATE_INCLUDE_DIRS})

link_directories(${GTKMM_LIBRARY_DIRS})
link_directories(${QALCULATE_LIBRARY_DIRS})


add_executable(${PROJECT_NAME} ${MAIN_SRC})

target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${QALCULATE_LIBRARIES})

enable_testing()
add_subdirectory(test)
add_test(var_processor test/var_processor)
