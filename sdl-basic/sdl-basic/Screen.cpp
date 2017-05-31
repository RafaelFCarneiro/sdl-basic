//
//  Screen.cpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 30/05/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#include "Screen.hpp"

namespace particles {

  Screen::Screen() :
    m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
  }
  
  bool Screen::init() {

    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
      std::cout << "SDL init failed." << std::endl;
      return false;
    }
    
    m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (m_window == NULL) {
      std::cout << "Could not create window: " << SDL_GetError() << std::endl;
      SDL_Quit();
      return false;
    }
    
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB888,
     SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if (m_renderer == NULL) {
      std::cout << "Could not create render: " << SDL_GetError() << std::endl;
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }
    
    if (m_texture == NULL) {
      std::cout << "Could not create texture: " << SDL_GetError() << std::endl;
      SDL_DestroyWindow(m_window);
      SDL_DestroyRenderer(m_renderer);
      SDL_Quit();
      return false;
    }
    
    m_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
    
    // setting collor 0 = black
    memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    
    for (int i=0; i<(SCREEN_WIDTH*SCREEN_HEIGHT)/3; i++) {
      m_buffer[i] = RED;
    }
    
    for (int i=(SCREEN_WIDTH*SCREEN_HEIGHT)/3; i<((SCREEN_WIDTH*SCREEN_HEIGHT)/3)*2; i++) {
      m_buffer[i] = GREEN;
    }
    for (int i=((SCREEN_WIDTH*SCREEN_HEIGHT)/3)*2; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
      m_buffer[i] = BLUE;
    }
    
    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
    
    return true;
  }
  
  bool Screen::processEvents(){
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        return false;
      }
    }
    
    return true;
  }
  
  void Screen::close() {
    delete []m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
  
  }

}
  