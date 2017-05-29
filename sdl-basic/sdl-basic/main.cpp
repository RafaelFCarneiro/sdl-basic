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
  
  SDL_Window *window = SDL_CreateWindow(
    "Particle Fire Explosion",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN
  );
  
  if (window == NULL) {
    std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 2;
  }
  
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
  
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
