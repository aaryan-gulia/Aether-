
#pragma once

#include "RenderObject.h"

#include <sys/types.h>
#include <vector>
#include <cstdint>

namespace AetherEngine {

  class AnimationObject{
    public:
      AnimationObject(std::vector<RenderObject> renderObjects, uint32_t maxAnimationFrames = 1):
      m_id(++objectCounter), m_RenderObjects(renderObjects), m_size(renderObjects.size()), 
      m_animationFramesCount(), m_maxAnimationFrames(maxAnimationFrames), animationComplete(false){}
      RenderObject& animateWithTicks();
      RenderObject& animateWithFrames();
      bool isAnimationComplete();

      uint32_t id() { return m_id; }
      static void resetObjectCounter() {objectCounter = 0;}

    private:
      static uint32_t objectCounter;
      const uint32_t m_id;
    
      std::vector<RenderObject> m_RenderObjects;
      const uint32_t m_size;
      
      uint32_t m_animationFramesCount;
      const uint32_t m_maxAnimationFrames;
      bool animationComplete;
  };
}
