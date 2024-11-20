
#pragma once

#include "RenderObject.h"

#include <vector>
#include <cstdint>

namespace AetherEngine {

  class AnimationObject{
    public:
      AnimationObject(std::vector<RenderObject> renderObjects, uint32_t maxAnimationFrames = 1):
      m_RenderObjects(renderObjects), m_size(renderObjects.size()), 
      m_animationFramesCount(), m_maxAnimationFrames(maxAnimationFrames), animationComplete(false){}
      RenderObject& animateWithTicks();
      RenderObject& animateWithFrames();
      bool isAnimationComplete();

    private:
      std::vector<RenderObject> m_RenderObjects;
      const uint32_t m_size;
      
      uint32_t m_animationFramesCount;
      const uint32_t m_maxAnimationFrames;
      bool animationComplete;
  };
}
