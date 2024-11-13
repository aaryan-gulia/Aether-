#include "Game.h"
#include "SDL_events.h"
#include "SDL_mutex.h"
#include "SDL_pixels.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "Window.h"

#include "SDL.h"

#include <cstdlib>
#include <iostream>

const uint32_t WindowHeight = 450;
const uint32_t WindowWidth = 800;
const char* WindowTitle = "Aether Souls";

void Game::run(){

  Window window(WindowHeight, WindowWidth, WindowTitle);
  auto win = window.getDrawWindow();

  SDL_FillRect(window.getDrawWindow(), NULL, SDL_MapRGB(window.getDrawWindow()->format, 100, 100, 100));
  window.update();
  
  SDL_Event event;
  
  while(!m_Quit){
    while(SDL_PollEvent(&event) != 0){
      if(event.type == SDL_QUIT){
        this->close();
      }
    }
  }
    
  SDL_Delay(5000);
}

void Game::initialise(){
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
    std::cout<<"SDL Initialise Failed!"<<std::endl;
  }

  std::cout<<"SDL Initialised"<<std::endl;
}

void Game::close(){
  SDL_Quit();
  m_Quit = true;
}

Game::~Game(){
  if(!m_Quit){
    SDL_Quit();
  }
}
