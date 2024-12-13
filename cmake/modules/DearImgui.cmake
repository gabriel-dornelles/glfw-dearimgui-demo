set(DEAR_IMGUI_SOURCE
    ${LIBRARIES_DIR}/DearImGui/source/backends/imgui_impl_glfw.cpp
    ${LIBRARIES_DIR}/DearImGui/source/backends/imgui_impl_opengl3.cpp
    ${LIBRARIES_DIR}/DearImGui/source/imgui.cpp
    ${LIBRARIES_DIR}/DearImGui/source/imgui_demo.cpp
    ${LIBRARIES_DIR}/DearImGui/source/imgui_draw.cpp
    ${LIBRARIES_DIR}/DearImGui/source/imgui_tables.cpp
    ${LIBRARIES_DIR}/DearImGui/source/imgui_widgets.cpp

    ${LIBRARIES_DIR}/DearImGui/include/backends/imgui_impl_glfw.h
    ${LIBRARIES_DIR}/DearImGui/include/backends/imgui_impl_opengl3.h
    ${LIBRARIES_DIR}/DearImGui/include/backends/imgui_impl_opengl3_loader.h
    ${LIBRARIES_DIR}/DearImGui/include/imconfig.h
    ${LIBRARIES_DIR}/DearImGui/include/imgui.h
    ${LIBRARIES_DIR}/DearImGui/include/imgui_internal.h
    ${LIBRARIES_DIR}/DearImGui/include/imstb_rectpack.h
    ${LIBRARIES_DIR}/DearImGui/include/imstb_textedit.h
    ${LIBRARIES_DIR}/DearImGui/include/imstb_truetype.h
)

set(DEAR_IMGUI_INCLUDE_DIRS
    ${LIBRARIES_DIR}/DearImGui/include/backends
    ${LIBRARIES_DIR}/DearImGui/include
)

include_directories(${DEAR_IMGUI_INCLUDE_DIRS})
add_library(lib_dearimgui ${DEAR_IMGUI_SOURCE})
