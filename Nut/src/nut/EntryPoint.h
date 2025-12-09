#pragma once
#include <iostream>

#ifdef NUT_PLATFORM_LINUX
int main(int argc, char** argv)
{
    Nut::Log::Init();
    Nut::Log::GetCoreLogger()->warn("Hello, Nut!");
    Nut::Log::GetClientLogger()->info("Hello, Client!");

    auto app = Nut::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#endif