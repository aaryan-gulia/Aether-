project(AetherSouls)

add_executable(${PROJECT_NAME} main.cpp
Game.cpp
ResourceManager.cpp
Map.cpp
Player.cpp
)

target_link_libraries(${PROJECT_NAME} GameEngine)
