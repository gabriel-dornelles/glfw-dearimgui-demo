#ifndef __APP_DESIGN_H__
#define __APP_DESIGN_H__

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class AppDesign
{
public:
    AppDesign();
    virtual ~AppDesign();

public:
    void Main();
    void DemoWindow();
};

#endif // __APP_DESIGN_H__
