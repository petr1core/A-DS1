cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME List)
project(${PROJECT_NAME})

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(ListLib)
add_subdirectory(ListTest)

file(GLOB srcs "*.cpp")
add_executable(${PROJECT_NAME} ${srcs})
target_link_libraries(${PROJECT_NAME} &{ListLib} gtest)


# List