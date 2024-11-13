#include "Game.h"
#include <thread>
#include <chrono>

void Game::run(){

  while(true){
    std::this_thread::sleep_for(std::chrono::nanoseconds(50000));
  }
  
}
