//
//  main.cpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 28/05/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

#include "Screen.hpp"

int main(int argc, const char * argv[]) {
  
  particles::Screen screen;
  
  if (screen.init() == false) {
    std::cout << "Error initialising SDL." << std::endl;
  }
  
  while(true) {
    //  Update particles
    for (int y=0; y < particles::Screen::SCREEN_HEIGHT; y++) {
      for (int x=0; x < particles::Screen::SCREEN_WIDTH; x++) {
        screen.setPixel(x, y, 128, 128, 128);
      }
    }
    
    screen.setPixel(400, 300, 255, 255, 255);
    
    //  Draw particles
    screen.update();
    
    //  Check for messages/events
    if (screen.processEvents() == false) {
      break;
    };
  }

  screen.close();
  
  return 0;
}
