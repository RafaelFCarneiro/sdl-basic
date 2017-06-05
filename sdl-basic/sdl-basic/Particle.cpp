//
//  Particle.cpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 03/06/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#include "Particle.hpp"

#include <stdlib.h>
#include <math.h>

namespace testproject {

  Particle::Particle() : m_x(0), m_y(0) {
    m_direction =  (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.001 * rand())/RAND_MAX;
  }
  
  Particle::~Particle() {}
  
  void Particle::update() {
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);
    
    m_x += xspeed;
    m_y += yspeed;
  }

}
