cmake_minimum_required(VERSION 3.30)

project(glfwImguiExample)

if (CMAKE_GENERATOR STREQUAL "Ninja")
    set(WITH_NINJA ON)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # for vscode
endif()

include(cmake/find_libraries.cmake)
add_subdirectory(source)
