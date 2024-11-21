#pragma once

#include "Engine.h"

#include "ResourceManager.h"
#include "SDL_render.h"
#include "SDL_events.h"
#include <cstdint>

class Player{
  public:
    Player();
    void handleEffect();
    void handleEvent(SDL_Event& event);
    void render();

    enum Direction{FRONT = 1, RIGHT = 2, BACK = 3, LEFT = 4,};

    enum Action{IDLE = 1,RUN = 2,ATTACK = 3, DYING = 4};

    enum State{FRONT_IDLE = 0, RIGHT_IDLE = 1, LEFT_IDLE = 2, BACK_IDLE = 3,
               FRONT_RUN = 4, RIGHT_RUN = 5, LEFT_RUN = 6, BACK_RUN = 7,
               FRONT_ATTACK = 8, RIGHT_ATTACK = 9, LEFT_ATTACK = 10, BACK_ATTACK = 11,
               DEAD = 12};
    
  private:
    int m_x = 0;
    int m_y = 0;
    int m_velocity = 10;
    int m_health = 100;
    int m_stamina = 100;
    Direction m_currDirection;
    Action m_currAction;
    State m_state;

    SDL_Rect m_srcRect;
    SDL_Rect m_dstRect;

    ResourceManager m_resourceManager;

    void setState();

    // void renderAttack(Window& window);
    // uint32_t attackAnimationFrameCounter(uint32_t maxFrames); 
    // void renderRun(Window& window);
    // void renderIdle(Window& window);
    // void render(Window& window, SDL_RendererFlip flip);
    // uint32_t SpriteColumn();
    // uint32_t SpriteRow(uint32_t MaxRow);
    // SDL_RendererFlip Flip();
    // void updateSrcRect(uint32_t spriteRow, uint32_t spriteCol);
};

