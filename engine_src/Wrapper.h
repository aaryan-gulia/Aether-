

#pragma once


#include"SDL.h"
#include"SDL2/SDL_image.h"
#include<iostream>


namespace AetherEngine {

class Rect{
  public:
    Rect(int x_position, int y_position, int width, int height);
    ~Rect();

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

class Renderer{
  public:
    Renderer(Window& window){
      m_renderer = window.getRenderer();
      
      if(!m_renderer){
        std::cout<<"Error creating SDL window surface: "<<SDL_GetError()<<std::endl;
      }   
    }


    SDL_Texture* loadTexture(const char* textureFileName){
      SDL_Surface* tempSurface = IMG_Load(textureFileName);
      SDL_Texture* tex = SDL_CreateTextureFromSurface(m_renderer, tempSurface);
      return tex;
    }

  private:
    SDL_Renderer* m_renderer = NULL;
};

class Texture{
  public:
    Texture(Renderer& renderer, const char* textureFileName){
      m_texture = renderer.loadTexture(textureFileName);

      if(!m_texture){
        std::cout<<"Error Loading SDL Texture"<<SDL_GetError();
      }
    }

  private:
    SDL_Texture* m_texture = NULL;
};
  
}

