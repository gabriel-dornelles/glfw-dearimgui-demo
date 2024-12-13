#include "app_design.hh"

AppDesign::AppDesign()
{
}

AppDesign::~AppDesign()
{
}

void AppDesign::Main()
{
    DemoWindow();
}

void AppDesign::DemoWindow()
{
    ImGui::ShowDemoWindow();
}
