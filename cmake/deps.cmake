if (NOT DEFINED LIBRARIES_DIR)
    set(LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/../libs)

    if (NOT EXISTS "${LIBRARIES_DIR}")
        message(FATAL_ERROR "Libraries not found!\n")
    endif()
endif()

include(cmake/modules/OpenGL.cmake)
include(cmake/modules/GLFW.cmake)
include(cmake/modules/DearImgui.cmake)

set(DEP_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/source/
    ${CMAKE_SOURCE_DIR}/source/app
    ${CMAKE_SOURCE_DIR}/source/utils
)
set(DEP_LIBS
    ${GLFW_LIBRARY}
    OpenGL32
    lib_dearimgui
)
