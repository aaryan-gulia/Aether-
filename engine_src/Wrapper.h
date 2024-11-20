

#pragma once


#include"SDL.h"
#include"SDL2/SDL_image.h"
#include<iostream>


namespace AetherEngine {

class Rect{
  public:
    Rect(int x_position, int y_position, uint32_t width, uint32_t height):m_rect(){
      m_rect.x = x_position;
      m_rect.y = y_position;
      m_rect.w = width;
      m_rect.h = height;
    }
    ~Rect() = default;

    Rect(Rect& rect) = delete;
    void operator=(Rect& rect) = delete;

    SDL_Rect* getRawRect(){ return &m_rect; }

  private:
    SDL_Rect m_rect;
};

class Window{
  public:
    Window(int width, int height, const char* title){
      m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

      if(!m_Window){
        std::cout<<"Error creating SDL window: "<<SDL_GetError()<<std::endl;
      }
    }

    SDL_Renderer* getRenderer(){
      SDL_Renderer* renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
      return renderer;
    }

  private:
    SDL_Window* m_Window = NULL;
};

  
}

