cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME Stack)
project(${PROJECT_NAME})

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

file(GLOB srcs "*.cpp")
add_executable(${PROJECT_NAME} ${srcs})
target_link_libraries(${PROJECT_NAME} ${StackLib} gtest)


# Stack