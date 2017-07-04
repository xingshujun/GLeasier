cmake_minimum_required(VERSION 3.1.0)

project(GLeasier
  VERSION 0.1
  LANGUAGES C CXX)

set(CMAKE_C_FLAGS "-g")
add_definitions(
  -D_GNU_SOURCE
  )

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -g")
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/CMake")
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")

find_package(PkgConfig REQUIRED)

find_package(GLEW  REQUIRED)
find_package(glm   REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(assimp REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)

pkg_search_module(GLFW REQUIRED glfw3)
include_directories(include)
add_subdirectory(common)

