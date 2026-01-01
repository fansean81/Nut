file(GLOB NUT_SOURCES
    src/nut/*.cpp
)

add_subdirectory(vendor/glfw)

if(UNIX AND NOT APPLE)
    list(APPEND NUT_SOURCES
        ../Platform/Linux/LinuxWindow.cpp
    )
endif()

add_library(nut SHARED ${NUT_SOURCES})

target_precompile_headers(nut PRIVATE
    src/nutpch.h
)

target_compile_definitions(nut PRIVATE NUT_BUILD_DLL=1)

if(UNIX AND NOT APPLE)
    target_compile_definitions(nut PUBLIC NUT_PLATFORM_LINUX)
elseif (WIN32)
    target_compile_definitions(nut PUBLIC NUT_PLATFORM_WINDOWS)
endif()

target_include_directories(nut PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../Platform/Linux
)

target_link_libraries(nut PUBLIC glfw)

if(UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    find_package(OpenGL REQUIRED)
    target_link_libraries(nut PUBLIC
        ${X11_LIBRARIES}
        ${OPENGL_LIBRARIES}
        pthread
        dl
        m
    )
endif()


add_custom_command(TARGET nut POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:nut>
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)