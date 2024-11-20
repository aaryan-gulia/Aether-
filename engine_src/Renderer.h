
#pragma once

#include"Wrapper.h"
#include"RenderObject.h"
#include "AnimationObject.h"
#include <cstdint>

namespace AetherEngine{

class Renderer{
  public:
    Renderer() = default;
    void Init(Window& window);

    SDL_Texture* loadTexture(const char* textureFileName) const;

    RenderObject loadRenderObject(SDL_Texture* texture, Rect* srcRect, bool flip = false);
    AnimationObject loadAnimationObject(SDL_Texture* texture, std::vector<Rect*> srcRects, 
                                        bool flip = false, uint32_t maxAnimationFrames = 1);

    void render(RenderObject& ro, int x_position, int y_position) const;
    void clear() const;
    void present() const;
    
  private:
    SDL_Renderer* m_renderer = NULL;
};

}
