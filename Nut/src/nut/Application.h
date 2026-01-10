#pragma once

#include "Core.h"
#include "events/Event.h"
#include "events/ApplicationEvent.h"

#include "Window.h"

namespace Nut
{
    class NUT_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &e);
    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined in client
    Application *CreateApplication();
} // namespace Nut