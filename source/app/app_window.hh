#ifndef __APP_WINDOW_H__
#define __APP_WINDOW_H__

#include <string>

struct GLFWwindow;
class AppImgui;

class AppWindow
{
public:
    AppWindow(int windowWidth, int windowHeight, std::string windowTitle);
    virtual ~AppWindow();

protected:
    // GLFW
    GLFWwindow* m_window;
    int         m_windowWidth;
    int         m_windowHeight;
    std::string m_windowTitle;
    bool        m_glfwContext;

    // Dear Imgui
    AppImgui*   m_appImgui;

private:
    static void ErrorCallback(int error, const char* description);
    static void InputCallback(GLFWwindow* window, int key, int scanCode, int actions, int mods);
    static void ResizeCallback(GLFWwindow* window, int width, int height);
    static void FramebufferResizeCallback(GLFWwindow* window, int width, int height);

public:
    void WindowMainLoop();

    int GetWindowWidth() const;
    int GetWindowHeight() const;
    std::string GetWindowTitle() const;
    
    void SetWindowSize(int newWidth, int newHeight);
    void SetWindowTitle(std::string newTitle);
};

#endif // __APP_WINDOW_H__
