

#pragma once

#include "Window.h"

class Game{

  public:
    
    Game(){};
    ~Game();

    void initialise();
    void close();
    void run();


    enum GameState{
      GAME_MENU = 1,
      GAME_PLAY = 2,
      GAME_QUIT = 0,
    };

    
  private:
    GameState m_state;
    
    void handleEvent(SDL_Event& event);

};
