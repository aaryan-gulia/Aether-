#include "Renderer.h"
#include "AnimationObject.h"
#include "RenderObject.h"
#include <cstdint>

using namespace AetherEngine;

void Renderer::Init(Window& window){
  m_renderer = window.getRenderer();
  if(!m_renderer){
    std::cout<<"Error creating SDL window surface: "<<SDL_GetError()<<std::endl;
  }   
}


SDL_Texture* Renderer::loadTexture(const char* textureFileName) const{
  SDL_Surface* tempSurface = IMG_Load(textureFileName);
  SDL_Texture* tex = NULL;
  tex = SDL_CreateTextureFromSurface(m_renderer, tempSurface);

  if(tex == NULL){
    std::cout<<"Could Not Load SDL Texture"<<SDL_GetError()<<std::endl;
  }

  return tex;
}

RenderObject Renderer::loadRenderObject(SDL_Texture* texture, Rect* srcRect, bool flip){
  SDL_RendererFlip sdlFlip = flip? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
  return RenderObject(texture, *srcRect, sdlFlip);
}

AnimationObject Renderer::loadAnimationObject(SDL_Texture* texture, std::vector<Rect*> srcRects, 
                                              bool flip, uint32_t maxAnimationFrames){
  SDL_RendererFlip sdlFlip = flip? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
  std::vector<RenderObject> animation;
  for(Rect* srcRect : srcRects){
    animation.emplace_back(texture,*srcRect, sdlFlip);
  }
  
  return {animation, maxAnimationFrames};
}

void Renderer::render(RenderObject& ro, int x_position, int y_position) const{
  auto srcRect = ro.getRawSrcRect();
  Rect dstRect(x_position, y_position, srcRect->w * ro.getScale(), srcRect->h * ro.getScale());
  SDL_RenderCopyEx(m_renderer, ro.getRawTexture(), srcRect, dstRect.getRawRect() , 0, NULL, ro.getRawFlip());
}

void Renderer::clear() const{
  SDL_RenderClear(m_renderer);
}

void Renderer::present() const{
  SDL_RenderPresent(m_renderer);
}
