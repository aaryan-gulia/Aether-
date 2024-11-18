#include "Window.h"
#include "ResourceManager.h"
#include "SDL_error.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include "Tile.h"
#include <iostream>


Window::Window(float height, float width, const char* title, bool fullscreen): 
m_WindowHeight(height), 
m_WindowWidth(width), 
m_FullScreen(fullscreen),
m_resourceManager()
{
  
  m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

  if(!m_Window){
    std::cout<<"Error creating SDL window: "<<SDL_GetError()<<std::endl;
  }
    
  m_Rendrer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

  if(!m_Rendrer){
    std::cout<<"Error creating SDL window surface: "<<SDL_GetError()<<std::endl;
  }

  m_resourceManager.init(m_Rendrer);
}

void Window::drawEntity(){
 
    SDL_Rect dst_rect;
    dst_rect.x = 100;
    dst_rect.y = 200;
    dst_rect.w = 32;
    dst_rect.h = 32;    

    SDL_RenderCopy(m_Rendrer, m_resourceManager.getTileTextures(), m_resourceManager.getTileSrcRect(Tile::WALL), &dst_rect);
    
    dst_rect.x = 300;
    dst_rect.y = 200;
    
    SDL_RenderCopy(m_Rendrer, m_resourceManager.getTileTextures(), m_resourceManager.getTileSrcRect(Tile::GRASS), &dst_rect);
    
}


SDL_Renderer* Window::getRenderer(){
  return m_Rendrer;
}

SDL_Window* Window::getWindow(){
  return m_Window;
}

void Window::clear(){
  SDL_RenderClear(m_Rendrer);
}

void Window::render(){
  SDL_RenderPresent(m_Rendrer);
}

