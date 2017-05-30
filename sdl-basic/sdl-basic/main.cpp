//
//  main.cpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 28/05/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[]) {

  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;
  
  if (SDL_Init(SDL_INIT_VIDEO) > 0) {
    std::cout << "SDL init failed." << std::endl;
    return 1;
  }
  
  SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  
  if (window == NULL) {
    std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 2;
  }
  
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888,
    SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
  
  if (renderer == NULL) {
    std::cout << "Could not create render: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 3;
  }
  
  if (texture == NULL) {
    std::cout << "Could not create texture: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 4;
  }
  
  Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
  
  // setting white - 0xFF is 255
  memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
  
  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
  
  bool quit = false;
  SDL_Event event;
  
  while(!quit) {
    //  Update particles
    //  Draw particles
    //  Check for messages/events
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }
  
  delete []buffer;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
