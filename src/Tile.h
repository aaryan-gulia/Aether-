
#pragma once

#include <cstdint>



class Tile{
  
  public:
  enum Type{
    GRASS = 0,
    WALL = 1
  };

  void setType(Type type){
    m_type = type;
  }
  void set_x(uint32_t x){
    m_x = x;
  }
  void set_y(uint32_t y){
    m_y = y;
  }
  uint32_t get_x(){ return m_x; }
  uint32_t get_y(){ return m_y; }
  uint32_t get_width(){ return m_width; }
  uint32_t get_height(){ return m_height; }
  Type get_type(){ return m_type; }

  private: 

  Type m_type;  
  uint32_t m_x;
  uint32_t m_y;
  uint32_t m_width = 32;
  uint32_t m_height = 32;

};
