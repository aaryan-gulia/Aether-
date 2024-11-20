#include "ResourceManager.h"
#include "Engine.h"

#include "SDL_rect.h"

#include "json/json.h"
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>

const char* TilesheetFile = "../resources/tilesheet.json";

void ResourceManager::init(const char* loading_instruction_file){
  std::ifstream loading_info_json(loading_instruction_file, std::ifstream::binary);

  Json::Value loading_info;
  loading_info_json >> loading_info;

  auto texture = Engine::loadTexture(loading_info["path"].asCString());
  int num_animations = loading_info["num_animations"].asInt();
  auto num_sprites_list = loading_info["num_sprites_per_animation"];
  auto max_frames_list = loading_info["max_frames_if_valid_else_0"];

  int x_padding = loading_info["x_padding"].asInt();
  int x_size = loading_info["x_size"].asInt();
  int x_spacing = loading_info["x_spaceing"].asInt();
  
  int y_padding = loading_info["y_padding"].asInt();
  int y_size = loading_info["y_size"].asInt();
  int y_spacing = loading_info["y_spaceing"].asInt();

  int num_flipped_animations = loading_info["num_flipped_animations"].asInt();
  auto flipped_animations_list = loading_info["flipped_animations"];
  std::vector<uint64_t> flipped_animations;
  for(uint32_t i = 0; i < num_flipped_animations; i++){
    flipped_animations.push_back(flipped_animations_list[i].asUInt64());
  }

  for(uint32_t animation = 0; animation < num_animations ;animation++){
    std::vector<AetherEngine::Rect> srcRects;

    for(uint32_t sprite = 0; sprite < num_sprites_list[animation].asInt(); sprite++){
      srcRects.emplace_back(
        int(x_padding + sprite*(x_spacing + x_size)),
        int(y_padding + sprite*(x_spacing + x_size)),
        uint32_t(x_size),
        uint32_t(y_size)
      );
    }

    uint32_t max_frames = max_frames_list[animation].asInt();

    m_AnimationObjectIds.emplace_back(Engine::loadAnimationObject(texture, srcRects, false, max_frames));
    if(std::find(flipped_animations.begin(), flipped_animations.end(), animation+1) != flipped_animations.end()){
      m_AnimationObjectIds.emplace_back(Engine::loadAnimationObject(texture, srcRects, true, max_frames));
    }
  }
}



