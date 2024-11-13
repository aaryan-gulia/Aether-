#include "SDL.h"
#include "SDL_surface.h"
#include "SDL_video.h"


class Window{
  float m_WindowHeight;
  float m_WindowWidth;
  bool m_FullScreen;

  SDL_Window* m_Window = NULL;
  SDL_Surface* m_DrawWindow = NULL;

  public:
  Window(float height, float width, const char* title, bool fullscreen = false);
  
  SDL_Surface* getDrawWindow();

  void update();
  
  ~Window(){
    SDL_DestroyWindow(m_Window);
  }

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;
  
};
