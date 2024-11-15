#include "Game.h"
#include "SDL_events.h"
#include "SDL_mutex.h"
#include "SDL_pixels.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "Window.h"

#include "SDL.h"

#include <cstdint>
#include <iostream>

const uint32_t WindowHeight = 450;
const uint32_t WindowWidth = 800;
const char* WindowTitle = "Aether Souls";

void Game::run(){

  Window window(WindowHeight, WindowWidth, WindowTitle);

  SDL_Event event;

  uint32_t x_cam = 0;
  uint32_t y_cam = 0;
  
  while(!m_Quit){
    while(SDL_PollEvent(&event) != 0){
      if(event.type == SDL_QUIT){
        this->close();
      }
      if(event.type == SDL_KEYDOWN){
        switch (event.key.keysym.scancode) {
          case SDL_SCANCODE_W: {
              y_cam += 10;
              break;
            }
          case SDL_SCANCODE_S: {
              y_cam -= 10;
              break;
            }
          case SDL_SCANCODE_D:{
              x_cam -= 10;
              break;
            }
          case SDL_SCANCODE_A:{
              x_cam += 10;
              break;
            }
        }
      }
    }

    SDL_SetRenderDrawColor(window.getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(window.getRenderer());
    

    SDL_Rect rect;
    rect.x = 100 + x_cam;
    rect.y = 200 + y_cam;
    rect.w = 200;
    rect.h = 200;    
    
    SDL_SetRenderDrawColor(window.getRenderer(), 255, 255, 255, 255);
    
    SDL_RenderDrawRect(window.getRenderer(), &rect);

    SDL_RenderPresent(window.getRenderer());
    
  }
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
