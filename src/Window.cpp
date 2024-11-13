#include "Window.h"
#include "SDL_error.h"
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
    
  m_DrawWindow = SDL_GetWindowSurface(m_Window);

  if(!m_DrawWindow){
    std::cout<<"Error creating SDL window surface: "<<SDL_GetError()<<std::endl;
  }
}

SDL_Surface* Window::getDrawWindow(){
  return m_DrawWindow;
}

void Window::update(){
  SDL_UpdateWindowSurface(m_Window);
}
