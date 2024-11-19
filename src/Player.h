

#pragma once

#include "SDL_assert.h"
#include "SDL_render.h"
#include "SDL_scancode.h"
#include "SDL_timer.h"
#include "Window.h"
#include "Map.h"

#include "SDL_events.h"
#include <cstdint>

class Player{
  public:
    Player();
    void handleEffect();
    void handleEvent(SDL_Event& event);
    void render(Window& window);

    enum Direction{
      FRONT = 1,
      RIGHT = 2,
      BACK = 3,
      LEFT = 4,
    };

    enum Action{
      IDLE = 1,
      RUN = 2,
      ATTACK = 3,
    };
    
  private:
    int m_x = 0;
    int m_y = 0;
    int m_velocity = 10;
    int m_health = 100;
    int m_stamina = 100;
    Direction m_currDirection;
    Action m_currAction;

    SDL_Rect m_srcRect;
    SDL_Rect m_dstRect;

    void renderAttack(Window& window);
    void renderRun(Window& window);
    void renderIdle(Window& window);
    void render(Window& window, SDL_RendererFlip flip);
    uint32_t SpriteColumn();
    uint32_t SpriteRow(uint32_t MaxRow);
    SDL_RendererFlip Flip();
    void updateSrcRect(uint32_t spriteRow, uint32_t spriteCol);
};

