#include "Player.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "Window.h"
#include <cstdint> 


const uint32_t MaxAttackRow = 3;
const uint32_t MaxRunRow = 5;
const uint32_t MaxIdleRow = 5;

const uint32_t AttackAnimationFrames = 60;


Player::Player(){
  m_resourceManager.init("../resources/player_sprite.json");
}

void Player::render(){
  setState();
  uint32_t animationId = m_resourceManager.getAnimationObjectIdAt(m_state);
  if(m_currAction == ATTACK){
    Engine::animateWithFrames(animationId, m_x, m_y);
    if(Engine::isAnimationComplete(animationId)){
      m_currAction = IDLE;
    }
  }
  else{
    Engine::animate(animationId, m_x, m_y);
  }
}

void Player::setState(){
  switch (m_currDirection) {
    case BACK:{
        switch (m_currAction) {
          case IDLE:
            m_state = BACK_IDLE;
            break;
          case ATTACK:
            m_state = BACK_ATTACK;
            break;
          case RUN:
            m_state = BACK_RUN;
            break;
        }
      } 
    case FRONT:{
        switch (m_currAction) {
          case IDLE:
            m_state = FRONT_IDLE;
            break;
          case ATTACK:
            m_state = FRONT_ATTACK;
            break;
          case RUN:
            m_state = FRONT_RUN;
            break;
        }
        
      }
    case RIGHT:{
        switch (m_currAction) {
          case IDLE:
            m_state = RIGHT_IDLE;
            break;
          case ATTACK:
            m_state = RIGHT_ATTACK;
            break;
          case RUN:
            m_state = RIGHT_RUN;
            break;
        }
        
      }
    case LEFT:{
        switch (m_currAction) {
          case IDLE:
            m_state = LEFT_IDLE;
            break;
          case ATTACK:
            m_state = LEFT_ATTACK;
            break;
          case RUN:
            m_state = LEFT_RUN;
            break;
        }
        
      }
  }
  if(m_currAction == DYING){
    m_state = DEAD;
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
      case SDL_SCANCODE_SPACE:
        m_currAction = ATTACK;
        break;
    }
  }
}


