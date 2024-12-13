#ifndef __APP_H__
#define __APP_H__

#include <string>

class AppWindow;

class App
{
public:
    App(int windowWidth, int windowHeight, std::string windowTitle);
    virtual ~App();

protected:
    AppWindow *m_appWindow;

public:
    void MainLoop();
};

#endif // __APP_H__
