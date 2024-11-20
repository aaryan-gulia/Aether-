project(AetherSouls)

add_executable(${PROJECT_NAME} main.cpp
Game.cpp
Map.cpp
)

target_link_libraries(${PROJECT_NAME} GameEngine)
