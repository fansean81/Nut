#pragma once
#include <iostream>

#ifdef NUT_PLATFORM_LINUX
int main(int argc, char** argv)
{
    Nut::Log::Init();
    NUT_CORE_WARN("Initialized Log!");
    int a = 5;
    NUT_INFO("Hello! Var={0}", a);

    auto app = Nut::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#endif