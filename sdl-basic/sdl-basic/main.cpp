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
    //  Draw particles
    //  Check for messages/events
    
    // Quit event
    if (screen.processEvents() == false) {
      break;
    };
  }

  screen.close();
  
  return 0;
}
