
#pragma once

#include <cstdint>



class Tile{
  
  public:
  enum Type{
    GRASS = 0,
    WALL = 1
  };

  private: 

  Type m_type;  
  uint32_t m_x;
  uint32_t m_y;
  uint32_t m_width = 16;
  uint32_t m_height = 16;

};
