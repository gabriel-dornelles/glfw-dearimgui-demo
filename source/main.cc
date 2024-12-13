#include "app.hh"

int main()
{
    App *app = new App(640, 480, "Application");
    
    app->MainLoop();

    delete app;
    app = nullptr;

    return 0;
}
