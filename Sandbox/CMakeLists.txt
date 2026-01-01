file(GLOB SANDBOX_SOURCES
    src/*.cpp
)

add_executable(sandbox ${SANDBOX_SOURCES})

target_include_directories(sandbox PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../Nut/vendor/spdlog/include
)

target_link_libraries(sandbox nut)

if(UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    find_package(OpenGL REQUIRED)
    target_link_libraries(sandbox
        ${X11_LIBRARIES}
        ${OPENGL_LIBRARIES}
        pthread
        dl
        m
    )
endif()