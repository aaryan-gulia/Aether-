#include "Window.h"
#include "SDL_error.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include <iostream>


Window::Window(float height, float width, const char* title, bool fullscreen): 
m_WindowHeight(height), 
m_WindowWidth(width), 
m_FullScreen(fullscreen){
  
  m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

  if(!m_Window){
    std::cout<<"Error creating SDL window: "<<SDL_GetError()<<std::endl;
  }
    
  m_Rendrer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

  if(!m_Rendrer){
    std::cout<<"Error creating SDL window surface: "<<SDL_GetError()<<std::endl;
  }
}


SDL_Renderer* Window::getRenderer(){
  return m_Rendrer;
}

SDL_Window* Window::getWindow(){
  return m_Window;
}

void Window::update(){
  SDL_RenderClear(m_Rendrer);
  SDL_RenderPresent(m_Rendrer);
}
