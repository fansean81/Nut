#include "nutpch.h"
#include "Application.h"
#include "events/ApplicationEvent.h"
#include "Log.h"

namespace Nut
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        NUT_TRACE(e.ToString());
        // while(true);
    }
}
