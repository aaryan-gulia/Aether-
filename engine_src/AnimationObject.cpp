
#include "AnimationObject.h"
#include "RenderObject.h"

using namespace AetherEngine;

RenderObject& AnimationObject::animateWithTicks(){
  return m_RenderObjects[(SDL_GetTicks()/100) % m_size];
}

RenderObject& AnimationObject::animateWithFrames(){
  if(m_animationFramesCount == m_maxAnimationFrames){
    m_animationFramesCount = 0;
    animationComplete = true;
  }
  else{
    animationComplete = false;
  }
  return m_RenderObjects[m_animationFramesCount++ * (m_size) / m_maxAnimationFrames];
}

bool AnimationObject::isAnimationComplete(){
  return animationComplete;
}

uint32_t AnimationObject::objectCounter = 0;
