
#pragma once

#include "AnimationObject.h"
#include "RenderObject.h"
#include <cstdint>

namespace AetherEngine{

class ResourceManager{
  public:
    void pushRenderObject(RenderObject& ro){
      m_renderObjects.emplace_back(ro);
    }
    
    void pushAnimationObject(AnimationObject& ao){
      m_animationObjects.emplace_back(ao);
    }

    RenderObject& getRenderObject(uint32_t id){
      for(RenderObject& ro : m_renderObjects){
        if(ro.id() == id){
          return ro;
        }
      }
      std::cout<<"No RenderObject with id: "<<id<<std::endl;
    }
    
    AnimationObject& getAnimationObject(uint32_t id){
      for(AnimationObject& ao : m_animationObjects){
        if(ao.id() == id){
          return ao;
        }
      }
      std::cout<<"No AnimationObject with id: "<<id<<std::endl;
    }
    


  private:
    std::vector<RenderObject> m_renderObjects;
    std::vector<AnimationObject> m_animationObjects;
};

class EntityResourceManager{
  public:

  private:
    std::vector<uint32_t> m_renderObjectIds;
    std::vector<uint32_t> m_renderObjectIndices;
    
    std::vector<uint32_t> m_animationObjectIds;
    std::vector<uint32_t> m_animationObjectIndices;
};

}
