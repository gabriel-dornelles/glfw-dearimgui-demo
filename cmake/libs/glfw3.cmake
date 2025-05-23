set(GLFW_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/glfw/include)

if(WITH_NINJA)
    set(GLFW_LIBRARY ${CMAKE_SOURCE_DIR}/libs/glfw/lib/libglfw3.a)
else()
    set(GLFW_LIBRARY ${CMAKE_SOURCE_DIR}/libs/glfw/lib/glfw3.lib)
endif()
