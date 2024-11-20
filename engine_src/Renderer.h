
#pragma once

#include"Wrapper.h"
#include"RenderObject.h"

namespace AetherEngine{

class Renderer{
  public:
    Renderer(Window& window){
      m_renderer = window.getRenderer();
      
      if(!m_renderer){
        std::cout<<"Error creating SDL window surface: "<<SDL_GetError()<<std::endl;
      }   
    }


    SDL_Texture* loadTexture(const char* textureFileName) const{
      SDL_Texture* tex = NULL;
      
      SDL_Surface* tempSurface = IMG_Load(textureFileName);
      tex = SDL_CreateTextureFromSurface(m_renderer, tempSurface);

      if(tex == NULL){
        std::cout<<"Could Not Load SDL Texture"<<SDL_GetError()<<std::endl;
      }

      return tex;
    }

    void render(RenderObject& ro, int x_position, int y_position) const{
      SDL_RenderCopyEx(m_renderer, ro.getRawTexture(), ro.getRawSrcRect(), dstRect.getRawRect() , 0, NULL, ro.getRawFlip());
    }
    
  private:
    SDL_Renderer* m_renderer = NULL;
};

}
