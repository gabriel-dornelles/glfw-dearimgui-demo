set(IMGUI_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/dearimgui/include)

set(INC
    ${CMAKE_SOURCE_DIR}/libs/dearimgui/include/
    ${CMAKE_SOURCE_DIR}/libs/dearimgui/include/backends
    ${GLFW_INCLUDE_DIR}
)

set(SRC
    ${CMAKE_SOURCE_DIR}/libs/dearimgui/src/backends/imgui_impl_glfw.cpp
    ${CMAKE_SOURCE_DIR}/libs/dearimgui/src/backends/imgui_impl_opengl3.cpp
    ${CMAKE_SOURCE_DIR}/libs/dearimgui/src/imgui_demo.cpp
    ${CMAKE_SOURCE_DIR}/libs/dearimgui/src/imgui_draw.cpp
    ${CMAKE_SOURCE_DIR}/libs/dearimgui/src/imgui_tables.cpp
    ${CMAKE_SOURCE_DIR}/libs/dearimgui/src/imgui_widgets.cpp
    ${CMAKE_SOURCE_DIR}/libs/dearimgui/src/imgui.cpp
)

set(LIBS
    ${GLFW_LIBRARY}
)

add_library(extern_imgui ${SRC})
target_include_directories(extern_imgui PRIVATE ${INC})
target_link_libraries(extern_imgui PRIVATE ${LIBS})
