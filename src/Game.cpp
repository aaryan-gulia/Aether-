#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "SDL_events.h"
#include "SDL_rect.h"
#include "SDL_render.h"

#include "SDL.h"

#include <cstdint>
#include <iostream>

const uint32_t WindowHeight = 450;
const uint32_t WindowWidth = 800;
const char* WindowTitle = "Aether Souls";

void Game::run(){

  Window window(WindowHeight, WindowWidth, WindowTitle);

  SDL_Event event;
  Map<100,100> map;
  Player player;
  map.init();
  

  while(m_state){

    while(SDL_PollEvent(&event) != 0){
      handleEvent(event);
      map.handleEvent(event);
      player.handleEvent(event);
    }
   
    window.clear();
    map.render(window);
    player.render(window);
    window.render();    
  }
}

void Game::initialise(){
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
    std::cout<<"SDL Initialise Failed!"<<std::endl;
  }

  std::cout<<"SDL Initialised"<<std::endl;
}

void Game::handleEvent(SDL_Event& event){
  if(event.type == SDL_QUIT){
    this->close();
  }
}

void Game::close(){
  SDL_Quit();
  m_state = GAME_QUIT;
}

Game::~Game(){
  if(m_state){
    SDL_Quit();
  }
}
