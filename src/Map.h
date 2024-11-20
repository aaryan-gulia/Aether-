
#pragma once

#include "Engine.h"
#include "Tile.h"
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include "json/json.h"
#include "fstream"

const char* TilesheetFile = "../resources/tilesheet.json";


struct Camera{
  int x;
  int y; 
};

template <size_t W, size_t H>
class Map{
  public:
  Map() = default;
  void init();
  void render();
  void handleEvent(SDL_Event& event);

  private:
    uint32_t m_width = W;
    uint32_t m_height = H;
    std::array<Tile,W * H> m_TileMap;
    Camera camera;
    int cam_velocity = 10;

    uint32_t wallRenderObjectId;
    uint32_t grassRenderObjectId;

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
void Map<W,H>::render(){

  for(Tile& tile: m_TileMap){
    SDL_Rect dst_rect;
    dst_rect.x = tile.get_x() * 32 + camera.x;
    dst_rect.y = tile.get_y() * 32 + camera.y;

    uint32_t id = tile.get_type() == Tile::WALL? wallRenderObjectId : grassRenderObjectId;
    Engine::render(id, tile.get_x() * 32, tile.get_y() * 32);

    
  }  
    
  
}


template<size_t W, size_t H>
void Map<W,H>::init(){
  genDefaultMap();  

  
  std::ifstream tilesheet_info_file(TilesheetFile, std::ifstream::binary);

  Json::Value tilesheet_info;
  tilesheet_info_file >> tilesheet_info;
  auto tilesheet_path = tilesheet_info["tilesheet_path"];


  Rect srcRectGrass(tilesheet_info["tiles"]["grass"]["x"].asInt(), 
                    tilesheet_info["tiles"]["grass"]["y"].asInt(), 32,32);
  Rect srcRectWall(tilesheet_info["tiles"]["wall"]["x"].asInt(), 
                    tilesheet_info["tiles"]["wall"]["y"].asInt(), 32,32);

  auto texture = Engine::loadTexture(tilesheet_path.asCString());
  wallRenderObjectId = Engine::loadRenderObject(texture, &srcRectWall);
  grassRenderObjectId = Engine::loadRenderObject(texture, &srcRectGrass);

  tilesheet_info_file.close();
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


