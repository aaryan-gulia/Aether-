
#pragma once

#include "SDL_rect.h"
#include "SDL_surface.h"
#include "SDL_image.h"
#include "Tile.h"

#include "SDL_render.h"
#include <cstdint>
#include <vector>


class ResourceManager{

  public:
    void init(const char* loading_instruction_file);
    
  private:

    std::vector<uint32_t> m_RenderObjectIds;
    std::vector<uint32_t> m_AnimationObjectIds;

};

