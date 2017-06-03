//
//  Screen.hpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 30/05/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <SDL2/SDL.h>
#include <iostream>
#include <iomanip>

namespace pui {
  class Screen {
  public:
    // SIZE
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

    // COLORS
    const static u_int32_t RED = 0xFF0000F;
    const static u_int32_t GREEN = 0x00FF00F;
    const static u_int32_t BLUE = 0x0000FFF;

  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
    
  public:
    Screen();
    bool init();
    bool processEvents();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void update();
    void close();
  };
}

#endif /* Screen_hpp */
