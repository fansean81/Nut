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

#ifdef NUT_ENABLE_ASSERTS
#define NUT_ASSERT(x, ...)                                   \
    {                                                        \
        if (!(x))                                            \
        {                                                    \
            NUT_ERROR("Assertion failed: {0}", __VA_ARGS__); \
            __debugbreak();                                  \
        }                                                    \
    }
#define NUT_CORE_ASSERT(x, ...)                                   \
    {                                                             \
        if (!(x))                                                 \
        {                                                         \
            NUT_ERROR("Core assertion failed: {0}", __VA_ARGS__); \
            __debugbreak();                                       \
        }                                                         \
    }
#else
#define NUT_ASSERTZ(x, ...)
#define NUT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)