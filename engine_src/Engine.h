
#pragma once

#include "AnimationObject.h"
#include "Wrapper.h"
#include "Renderer.h"
#include "RenderObject.h"
#include "ResourceManager.h"

#include <cstdint>
#include <sys/types.h>
#include <unordered_set>

namespace AetherEngine {

  
class AetherEngine{
  public:

    static void Init(uint32_t windowHeight, uint32_t windowWidth, const char* title){
      if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout<<"SDL Initialise Failed!"<<std::endl;
      }

      m_window.Init(windowWidth, windowWidth, title);
      m_renderer.Init(m_window);

      RenderObject::resetObjectCounter();
      AnimationObject::resetObjectCounter();
    }

    static SDL_Texture* loadTexture(const char* textureFileName){
      return m_renderer.loadTexture(textureFileName);
    }
    
    static uint32_t loadRenderObject(SDL_Texture* texture, Rect* srcRect, bool flip = false){
      RenderObject ro = m_renderer.loadRenderObject(texture, srcRect, flip);
      m_resourceManager.pushRenderObject(ro);
      return ro.id();
    }

    static uint32_t loadAnimationObject(SDL_Texture* texture, std::vector<Rect*> srcRects, 
                                        bool flip = false, uint32_t maxAnimationFrames = 1){
      AnimationObject ao = m_renderer.loadAnimationObject(texture, srcRects, flip, maxAnimationFrames);
      m_resourceManager.pushAnimationObject(ao);
      return ao.id();
    }

    static void render(uint32_t renderObjectId, int x, int y){
      m_renderer.render(m_resourceManager.getRenderObject(renderObjectId), x, y);
    } 

    static void animate(uint32_t animationObjectId, int x, int y){
      m_renderer.render(m_resourceManager.getAnimationObject(animationObjectId).animateWithTicks(), x, y);
    }
    
    static void animateWithFrames(uint32_t animationObjectId, int x, int y){
      m_renderer.render(m_resourceManager.getAnimationObject(animationObjectId).animateWithFrames(), x, y);
    }

    static bool isAnimationComplete(uint32_t animationObjectId, int x, int y){
      return m_resourceManager.getAnimationObject(animationObjectId).isAnimationComplete();
    }

    static void ShutDown();

    ~AetherEngine();

  private:
    static Window m_window;
    static Renderer m_renderer;
    static ResourceManager m_resourceManager;
};
}

