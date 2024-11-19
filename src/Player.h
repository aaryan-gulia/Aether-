

#pragma once

#include "SDL_scancode.h"
#include "SDL_timer.h"
#include "Window.h"
#include "Map.h"

#include "SDL_events.h"

class Player{
  public:
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

    void getSrcRect();
};

