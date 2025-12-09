#pragma once

#ifdef NUT_PLATFORM_LINUX
    #ifdef NUT_BUILD_DLL
        #define NUT_API __attribute__((visibility("default")))
    #else
        #define NUT_API
    #endif
#else
    #ifdef NUT_BUILD_DLL
        #define NUT_API __declspec(dllexport)
    #else
        #define NUT_API __declspec(dllimport)
    #endif
#endif