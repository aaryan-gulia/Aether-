#include "Player.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include <cstdint> 


void Player::render(Window& window){
  auto ticks = SDL_GetTicks();
  uint32_t spriteRow = m_currAction == ATTACK? (ticks/100) % 4 : (ticks/100) % 6;
  uint32_t spriteColumn = 3 * (m_currAction - 1) ;
  SDL_RendererFlip flip = SDL_FLIP_NONE;
  if(m_currDirection == LEFT){
    flip = SDL_FLIP_HORIZONTAL;
    spriteColumn += 1;
  }
  else{
    spriteColumn += m_currDirection - 1;
  }

  SDL_Rect src;
  src.x = 10 + spriteRow * 48;
  src.y = 10 + spriteColumn * 48;
  src.w = 40;
  src.h = 40;

  SDL_Rect dst;
  dst.x = m_x;
  dst.y = m_y;
  dst.w = 80;
  dst.h = 80;

  
  auto renderer = window.getRenderer();
  auto resourceManager = window.getResourceManager();
  SDL_RenderCopyEx(renderer, resourceManager->getPlayerTextures(), &src, &dst, 0, NULL, flip);

  if(m_currAction == ATTACK){
    if(spriteRow == 3){
      m_currAction = IDLE;
    }
  }
  else if (m_currAction == RUN) {
    if(spriteRow == 5){
      m_currAction = IDLE;
    }
  }
}

void Player::handleEvent(SDL_Event& event){
  
  if(event.type == SDL_KEYDOWN){
    switch (event.key.keysym.scancode) {
      case SDL_SCANCODE_W:
        m_currDirection = BACK;
        m_currAction = RUN;
        m_y -= m_velocity;
        break;
      case SDL_SCANCODE_S:
        m_currDirection = FRONT;
        m_currAction = RUN;
        m_y += m_velocity;
        break;
      case SDL_SCANCODE_D:
        m_currDirection = RIGHT;
        m_currAction = RUN;
        m_x += m_velocity;
        break;
      case SDL_SCANCODE_A:
        m_currDirection = LEFT;
        m_currAction = RUN;
        m_x -= m_velocity;
        break;
    }
  }
  else if(event.type == SDL_KEYUP && event.key.keysym.scancode == SDL_SCANCODE_H){
    m_currAction = ATTACK;
  }
  
}

void updateSrcRect(){
  SDL_Rect src; 
}

