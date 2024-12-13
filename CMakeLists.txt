cmake_minimum_required(VERSION 3.30)

project(App)

# Find dependencies
include(cmake/deps.cmake)

set(SOURCES
    source/main.cc
    source/app/app.cc
    source/app/app_design.cc
    source/app/app_imgui.cc
    source/app/app_window.cc

    source/app/app.hh
    source/app/app_design.hh
    source/app/app_imgui.hh
    source/app/app_window.hh
)

add_executable(App ${SOURCES})

# set startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT App)

target_include_directories(App PRIVATE ${DEP_INCLUDE_DIRS})
target_link_libraries(App PRIVATE ${DEP_LIBS})
