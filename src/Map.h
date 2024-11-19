
#pragma once

#include "Window.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>

class Tile;

template <size_t W, size_t H>
class Map{
  public:
  Map() = default;
  void init();
  void render(Window& window);
  void handleEvent(SDL_Event& event);

  private:
    uint32_t m_width = W;
    uint32_t m_height = H;
    std::array<Tile,W * H> m_TileMap;
    Camera camera;
    int cam_velocity = 10;

    void genDefaultMap();
    std::array<size_t,2> getCoordFromIndex(size_t index);
};

template <size_t W, size_t H>
void Map<W,H>::handleEvent(SDL_Event& event){

  if(event.type == SDL_KEYDOWN){
    switch (event.key.keysym.scancode) {
      case SDL_SCANCODE_W:
        camera.y += cam_velocity;
        break;
      case SDL_SCANCODE_S:
        camera.y -= cam_velocity;
        break;
      case SDL_SCANCODE_D:
        camera.x -= cam_velocity;
        break;
      case SDL_SCANCODE_A:
        camera.x += cam_velocity;
        break;
    }
  }
}

template <size_t W, size_t H>
void Map<W,H>::render(Window& window){

  auto renderer = window.getRenderer();
  auto resourceManager = window.getResourceManager();


  for(Tile& tile: m_TileMap){
    SDL_Rect dst_rect;
    dst_rect.x = tile.get_x() * 32 + camera.x;
    dst_rect.y = tile.get_y() * 32 + camera.y;
    dst_rect.w = tile.get_width();
    dst_rect.h = tile.get_height();    

    SDL_RenderCopy(renderer, resourceManager->getTileTextures()  ,resourceManager->getTileSrcRect(tile.get_type()), &dst_rect);
    
  }  
    
  
}

template<size_t W, size_t H>
void Map<W,H>::init(){
  genDefaultMap();  
}

template<size_t W, size_t H>
void Map<W,H>::genDefaultMap(){
  for(size_t i = 0; i < m_TileMap.size(); i++){
    auto coord = getCoordFromIndex(i);
    Tile& currTile = m_TileMap[i];
    if(coord[0] == 10 && coord[1] == 10){
      currTile.setType(Tile::WALL);
    }
    else if(coord[0] == 11 && coord[1] == 10){
      currTile.setType(Tile::WALL);
    }
    else if(coord[0] == 10 && coord[1] == 11){
      currTile.setType(Tile::WALL);
    }
    else if(coord[0] == 11 && coord[1] == 11){
      currTile.setType(Tile::WALL);
    }
    else{
      currTile.setType(Tile::GRASS);
    }

    currTile.set_x(coord[0]);
    currTile.set_y(coord[1]);
  }
}

template <size_t W, size_t H>
std::array<size_t,2> Map<W,H>::getCoordFromIndex(size_t index){
  size_t x = index % W;
  size_t y = index / W;
  return std::array<size_t, 2>{x,y};
}


