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
#include "Swarm.hpp"


int main(int argc, const char * argv[]) {
  
  srand((int)time(NULL));
  
  testproject::Screen screen;
  
  if (screen.init() == false) {
    std::cout << "Error initialising SDL." << std::endl;
  }
  
  testproject::Swarm swarm;  
  
  
  while(true) {
    //  Update particles
    
    //  Draw particles
    int elapsed = SDL_GetTicks();
    
    unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
    unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
    unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
    
    const testproject::Particle *const pParticles = swarm.getParticles();

    for (int i=0; i<testproject::Swarm::NPARTICLES; i++) {
      testproject::Particle particle = pParticles[i];
      
      int x = (particle.m_x + 1) * (testproject::Screen::SCREEN_WIDTH/2);
      int y = (particle.m_y + 1) * (testproject::Screen::SCREEN_HEIGHT/2);
      
      screen.setPixel(x, y, red, green, blue);
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
