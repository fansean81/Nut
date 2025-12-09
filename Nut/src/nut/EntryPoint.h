#pragma once
#include <iostream>

#ifdef NUT_PLATFORM_LINUX
int main(int argc, char** argv)
{
    std::cout << "Hello, Nut!" << std::endl;

    auto app = Nut::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#endif