
#pragma once

#include "RenderObject.h"

namespace AetherEngine {

  class AnimationObject{
    public:
      AnimationObject() = default;
      void push(RenderObject ro);

    private:
      std::vector<RenderObject> m_RenderObjects;
  };

}
