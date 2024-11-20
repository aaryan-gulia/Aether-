#include "Game.h"
#include "Map.h"

#include "SDL_events.h"
#include "SDL.h"

#include "Engine.h"

#include <cstdint>
#include <iostream>

const uint32_t WindowHeight = 450;
const uint32_t WindowWidth = 800;
const char* WindowTitle = "Aether Souls";

void Game::run(){

  SDL_Event event;
  Map<50,50> map;
  map.init();
  

  while(m_state){

    while(SDL_PollEvent(&event) != 0){
      handleEvent(event);
      map.handleEvent(event);
    }
   
    Engine::clear();
    map.render();
    Engine::present();    
  }
}

void Game::initialise(){
  Engine::Init(WindowHeight, WindowWidth, WindowTitle);
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
