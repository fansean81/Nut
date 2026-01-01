#pragma once

#include "Core.h"
#include "events/Event.h"
#include "Window.h"

namespace Nut
{
    class NUT_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined in client
    Application *CreateApplication();
} // namespace Nut