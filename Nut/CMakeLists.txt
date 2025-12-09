file(GLOB NUT_SOURCES
    src/nut/*.cpp
)

add_library(nut SHARED ${NUT_SOURCES})

if(UNIX AND NOT APPLE)
    target_compile_definitions(nut PUBLIC NUT_PLATFORM_LINUX)
elseif (WIN32)
    target_compile_definitions(nut PUBLIC NUT_PLATFORM_WINDOWS)
endif()

target_include_directories(nut PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

add_custom_command(TARGET nut POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:nut>
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)