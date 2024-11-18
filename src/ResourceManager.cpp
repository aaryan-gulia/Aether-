#include "ResourceManager.h"
#include "SDL_rect.h"

#include "json/json.h"
#include <cstdint>
#include <fstream>
#include <iostream>

const char* TilesheetFile = "../resources/tilesheet.json";

void ResourceManager::init(SDL_Renderer* renderer){
  loadTileTextures(TilesheetFile, renderer);
  loadTileSrcRects(TilesheetFile);
}



void ResourceManager::loadTileTextures(const char* json_file_name, SDL_Renderer* renderer){

  std::ifstream tilesheet_info_file(json_file_name, std::ifstream::binary);

  Json::Value tilesheet_info;
  tilesheet_info_file >> tilesheet_info;

  auto tilesheet_path = tilesheet_info["tilesheet_path"];

  SDL_Surface* tempSurface = IMG_Load(tilesheet_path.asCString());
  SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
  m_TilesTextures = tex;

  if(!m_TilesTextures){
    std::cout<<"Error creating SDL Texture: "<<SDL_GetError()<<std::endl;    
  }

  tilesheet_info_file.close();
}

void ResourceManager::loadTileSrcRects(const char* json_file_name){
  std::ifstream tilesheet_info_file(json_file_name, std::ifstream::binary);
  Json::Value tilesheet_info;
  tilesheet_info_file >> tilesheet_info;

  std::cout<<tilesheet_info;

  m_TilesSrcRects.emplace_back(buildTileSrcRect(tilesheet_info["tiles"]["grass"]["x"].asInt(), 
                                                tilesheet_info["tiles"]["grass"]["y"].asInt()));
  m_TilesSrcRects.emplace_back(buildTileSrcRect(tilesheet_info["tiles"]["wall"]["x"].asInt(), 
                                                tilesheet_info["tiles"]["wall"]["y"].asInt()));

  tilesheet_info_file.close();
}

SDL_Rect ResourceManager::buildTileSrcRect(uint32_t x_pos, uint32_t y_pos){
  SDL_Rect src_rect;
  src_rect.x = x_pos;
  src_rect.y = y_pos;
  src_rect.h = 32;
  src_rect.w = 32;

  return src_rect;
}

SDL_Texture* ResourceManager::getTileTextures(){
  return m_TilesTextures;
}

SDL_Rect* ResourceManager::getTileSrcRect(Tile::Type type){
  return &m_TilesSrcRects.at(type);
}
