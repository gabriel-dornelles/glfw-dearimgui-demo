#include "app.hh"
#include "app_window.hh"

App::App(int windowWidth, int windowHeight, std::string windowTitle)
	:m_appWindow(nullptr)
{
	m_appWindow = new AppWindow(windowWidth, windowHeight, windowTitle);
}

App::~App()
{
	if (m_appWindow)
	{
		delete m_appWindow;
		m_appWindow = nullptr;
	}
}

void App::MainLoop()
{
	m_appWindow->WindowMainLoop();
}
