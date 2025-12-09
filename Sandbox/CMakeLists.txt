file(GLOB SANDBOX_SOURCES
    src/*.cpp
)

add_executable(sandbox ${SANDBOX_SOURCES})

target_link_libraries(sandbox PRIVATE nut)