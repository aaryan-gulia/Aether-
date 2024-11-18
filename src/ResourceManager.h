
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

  void init(SDL_Renderer* renderer);

  SDL_Rect* getTileSrcRect(Tile::Type type);
  SDL_Texture* getTileTextures();
  
  private:
  SDL_Texture* m_TilesTextures = NULL;
  std::vector<SDL_Rect> m_TilesSrcRects; 

  void loadTileTextures(const char* json_file_name, SDL_Renderer* renderer);
  void loadTileSrcRects(const char* json_file_name);
  SDL_Rect buildTileSrcRect(uint32_t x_pos, uint32_t y_pos);
};

