cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+

# Generate compile_commands.json
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()


add_subdirectory(engine_src)
add_subdirectory(src)


execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        src/compile_commands.json
        compile_commands.json
)
