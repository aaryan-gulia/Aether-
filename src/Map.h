
#pragma once

#include "Window.h"

#include <array>
#include <cstddef>
#include <cstdint>

class Tile;

template <size_t W, size_t H>
class Map{
  Map();
  void render()

  private:
    uint32_t m_width = W;
    uint32_t m_height = H;
    std::array<Tile,W * H> tile_map;
};
