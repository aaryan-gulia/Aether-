#include "Player.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "Window.h"
#include <cstdint> 


const uint32_t MaxAttackRow = 3;
const uint32_t MaxRunRow = 5;
const uint32_t MaxIdleRow = 5;


Player::Player(){
  m_srcRect.h = 40;
  m_srcRect.w = 40;

  m_dstRect.h = 80;
  m_dstRect.w = 80;
}

void Player::render(Window& window){
  m_dstRect.x = m_x;
  m_dstRect.y = m_y;
  switch (m_currAction) {
    case IDLE: 
      renderIdle(window);
      break;
    case ATTACK:
      renderAttack(window);
      break;
    case RUN:
      renderRun(window);
      break;
  }
}

void Player::renderAttack(Window& window){
  auto spriteRow = SpriteRow(MaxAttackRow);
  updateSrcRect(spriteRow, SpriteColumn());
  render(window, Flip());

  if(spriteRow == MaxAttackRow)
    m_currAction = IDLE;
}

void Player::renderRun(Window& window){
  auto spriteRow = SpriteRow(MaxRunRow);
  updateSrcRect(spriteRow, SpriteColumn());
  render(window,Flip());

  if(spriteRow == MaxRunRow)
    m_currAction = IDLE;
}

void Player::renderIdle(Window& window){
  updateSrcRect(SpriteRow(MaxIdleRow), SpriteColumn());
  render(window,Flip());
}

void Player::updateSrcRect(uint32_t spriteRow,uint32_t spriteCol){
  m_srcRect.x = 10 + spriteRow * 48;
  m_srcRect.y = 10 + spriteCol * 48; 
}

void Player::render(Window& window, SDL_RendererFlip flip){  
  auto renderer = window.getRenderer();
  auto resourceManager = window.getResourceManager();
  SDL_RenderCopyEx(renderer, resourceManager->getPlayerTextures(), &m_srcRect, &m_dstRect, 0, NULL, flip);
}

uint32_t Player::SpriteColumn(){
  uint32_t spriteColumn = 3 * (m_currAction - 1) ;
  return m_currDirection == LEFT? spriteColumn + 1 : spriteColumn + m_currDirection - 1;
}

uint32_t Player::SpriteRow(uint32_t MaxRow){
  return (SDL_GetTicks()/100) % (1 + MaxRow);
}

SDL_RendererFlip Player::Flip(){
  return m_currDirection == LEFT? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
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
      case SDL_SCANCODE_SPACE:
        m_currAction = ATTACK;
        break;
    }
  }
  
}

void updateSrcRect(){
  SDL_Rect src; 
}

