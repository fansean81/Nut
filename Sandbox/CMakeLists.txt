file(GLOB SANDBOX_SOURCES
    src/*.cpp
)

add_executable(sandbox ${SANDBOX_SOURCES})

target_include_directories(sandbox PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../Nut/vendor/spdlog/include
)

target_link_libraries(sandbox PRIVATE nut)