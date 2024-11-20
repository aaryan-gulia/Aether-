
#pragma once

#include"SDL.h"
#include "Wrapper.h"
#include <cstdint>
#include <vector>

namespace AetherEngine {
  class RenderObject{
    public:
      RenderObject(SDL_Texture* texture, Rect& srcRect, SDL_RendererFlip flip = SDL_FLIP_NONE, float scaling = 1)
      :m_Texture(texture), m_SrcRect(*srcRect.getRawRect()), m_scaling(scaling), m_flip(flip), m_id(++objectCounter){}

      ~RenderObject() = default;

      SDL_Texture* getRawTexture() const{
        return m_Texture;
      }

      const SDL_Rect* getRawSrcRect() const{
        return &m_SrcRect;
      }

      const SDL_RendererFlip& getRawFlip() const{
        return m_flip;
      }

      const uint32_t getScale() const{
        return m_scaling;
      }

      const uint32_t id() const{
        return m_id;
      }

      static void resetObjectCounter(){
        objectCounter = 0;
      }
      
    private:
      SDL_Texture* m_Texture;      
      const SDL_Rect m_SrcRect;
      const float m_scaling;
      const SDL_RendererFlip m_flip;
      const uint32_t m_id;

      static uint32_t objectCounter;
  };

}

