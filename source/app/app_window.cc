#include <cstdlib>
#include <cstdio>

#include "GLFW/glfw3.h"

#include "app_window.hh"
#include "app_imgui.hh"

AppWindow::AppWindow(int windowWidth, int windowHeight, std::string windowTitle)
    :m_window(nullptr),
     m_windowWidth(windowWidth),
     m_windowHeight(windowHeight),
     m_windowTitle(windowTitle),
     m_glfwContext(false),
     m_appImgui(nullptr)
{
    // set errors callback
    glfwSetErrorCallback(ErrorCallback);

    // try initialize glfw
    m_glfwContext = glfwInit();
    if (!m_glfwContext) {
        exit(-1);
    }

    // set OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // create window
    m_window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
    if (m_window == nullptr) {
        exit(-1);
    }

    // other callbacks
    glfwSetKeyCallback(m_window, InputCallback);
    glfwSetFramebufferSizeCallback(m_window, FramebufferResizeCallback);
    glfwSetWindowSizeCallback(m_window, ResizeCallback);

    // a pointer to our own window instance
    glfwSetWindowUserPointer(m_window, reinterpret_cast<void *>(this));

    // set context
    glfwMakeContextCurrent(m_window);
    printf("Context Set for OpenGL Version %s\n", glGetString(GL_VERSION));

    // start Dear ImGui
    m_appImgui = new AppImgui(m_window);
}

AppWindow::~AppWindow()
{
    // destroy Dear Imgui
    if (m_appImgui)
    {
        delete m_appImgui;
        m_appImgui = nullptr;
    }

    // destroy Window
    if (m_window)
    {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }

    // destroy GLFW
    if (m_glfwContext) {
        glfwTerminate();
        m_glfwContext = false;
    }
}

void AppWindow::ErrorCallback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void AppWindow::InputCallback(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
    // AppWindow *app = reinterpret_cast<AppWindow *>(glfwGetWindowUserPointer(window));
    // if (app == nullptr) {
    //     exit(-1);
    // }
    // if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    //     glfwSetWindowShouldClose(app->m_window, GLFW_TRUE);
    // }
}

void AppWindow::ResizeCallback(GLFWwindow* window, int width, int height)
{
}

void AppWindow::FramebufferResizeCallback(GLFWwindow* window, int width, int height)
{
    AppWindow *app = reinterpret_cast<AppWindow *>(glfwGetWindowUserPointer(window));
    if (app == nullptr) {
        exit(-1);
    }

    app->m_windowWidth  = width;
    app->m_windowHeight = height;
}

void AppWindow::WindowMainLoop()
{
    while(!glfwWindowShouldClose(m_window))
    {
        m_appImgui->NewFrame();
        
        glfwGetFramebufferSize(m_window, &m_windowWidth, &m_windowHeight);
        glViewport(0, 0, m_windowWidth, m_windowHeight);

        glClearColor(0.08f, 0.08f, 0.08f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_appImgui->Render();
        
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
}

int AppWindow::GetWindowWidth() const
{
    return m_windowWidth;
}

int AppWindow::GetWindowHeight() const
{
    return m_windowHeight;
}

std::string AppWindow::GetWindowTitle() const
{
    return m_windowTitle;
}

void AppWindow::SetWindowSize(int newWidth, int newHeight)
{
    glfwSetWindowSize(m_window, newWidth, newHeight);
}

void AppWindow::SetWindowTitle(std::string newTitle)
{
    glfwSetWindowTitle(m_window, newTitle.c_str());
    m_windowTitle = newTitle;
}
