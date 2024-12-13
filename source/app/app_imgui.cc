#include <cstdlib>
#include <cstdio>

#include "app_imgui.hh"
#include "app_design.hh"

AppImgui::AppImgui(GLFWwindow* window)
    :m_context(nullptr),
     m_appDesign(nullptr)
{
    IMGUI_CHECKVERSION();

    m_context = ImGui::CreateContext();
    if (m_context == nullptr) {
        exit(-1);
    }

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    printf("Dear ImGui: Context Created\nDear ImGui: Version %s\n", IMGUI_VERSION);

    m_appDesign = new AppDesign();
}

AppImgui::~AppImgui()
{
    if (m_appDesign)
    {
        delete m_appDesign;
        m_appDesign = nullptr;
    }
    
    if (m_context)
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        m_context = nullptr;
    }
}

void AppImgui::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    
    m_appDesign->Main();
}

void AppImgui::Render()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
