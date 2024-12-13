#ifndef __APP_IMGUI_H__
#define __APP_IMGUI_H__

struct GLFWwindow;
struct ImGuiContext;
class  AppDesign;

class AppImgui
{
public:
    AppImgui(GLFWwindow* window);
    virtual ~AppImgui();

private:
   ImGuiContext* m_context;

public:
    AppDesign* m_appDesign;

    void NewFrame();
    void Render();
};

#endif // __APP_IMGUI_H__
