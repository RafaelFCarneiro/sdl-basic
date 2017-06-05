//
//  main.cpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 28/05/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Screen.hpp"


int main(int argc, const char * argv[]) {
  
  srand(time(NULL));
  
  testproject::Screen screen;
  
  if (screen.init() == false) {
    std::cout << "Error initialising SDL." << std::endl;
  }
  
  
  while(true) {
    //  Update particles
    
    //  Draw particles
    int elapsed = SDL_GetTicks();
    unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
    unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
    unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
    
    for (int y=0; y < testproject::Screen::SCREEN_HEIGHT; y++) {
      for (int x=0; x < testproject::Screen::SCREEN_WIDTH; x++) {
        screen.setPixel(x, y, red, green, blue);
      }
    }
    
    //  Draw screen
    screen.update();
    
    //  Check for messages/events
    if (screen.processEvents() == false) {
      break;
    };
  }

  screen.close();
  
  return 0;
}
