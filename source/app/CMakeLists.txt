set(INC
    .

    # extern libs
    ${GLFW_INCLUDE_DIR}
    ${IMGUI_INCLUDE_DIR}
)

set(SRC
    main.cpp
)

set(LIBS
    opengl32
    ${GLFW_LIBRARY}
    extern_imgui
)

add_executable(application ${SRC})
set_target_properties(application PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin
)

if (NOT WITH_NINJA)
    set_property(DIRECTORY ${CMAKE_BINARY_DIR} PROPERTY VS_STARTUP_PROJECT application)
endif()

target_include_directories(application PRIVATE ${INC})
target_link_libraries(application PRIVATE ${LIBS})
