#pragma once

#include "ResourceManager.h"

#include "SDL.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include <cstdint>




class Window{
  float m_WindowHeight;
  float m_WindowWidth;
  bool m_FullScreen;
  ResourceManager m_resourceManager;  

  SDL_Window* m_Window = NULL;
  SDL_Renderer* m_Rendrer = NULL;
  
  public:
  Window(float height, float width, const char* title, bool fullscreen = false);

  void clear();
  void render();

  void drawEntity();
  
  SDL_Renderer* getRenderer();
  ResourceManager* getResourceManager();
  SDL_Window* getWindow();

  ~Window(){
    SDL_DestroyRenderer(m_Rendrer);
    SDL_DestroyWindow(m_Window);
  }

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;
  
};


struct Camera{
  int x = 0;
  int y = 0;
  int x_min;
  int x_max;
  int y_min;
  int y_max;  
};
