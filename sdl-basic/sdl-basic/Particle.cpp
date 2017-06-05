//
//  Particle.cpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 03/06/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#include "Particle.hpp"
#include <stdlib.h>

namespace testproject {

  Particle::Particle() {
    m_x = ((2.0 * rand())/RAND_MAX) - 1;
    m_y = ((2.0 * rand())/RAND_MAX) - 1;

    m_xspeed = 0.001 * (((2.0 * rand())/RAND_MAX) - 1);
    m_yspeed = 0.001 * (((2.0 * rand())/RAND_MAX) - 1);

  }
  
  Particle::~Particle() {}
  
  void Particle::update() {
    m_x += m_xspeed;
    m_y += m_yspeed;
    
    if (m_x <= -1.0 || m_x >= 1.0) {
      m_xspeed = -m_xspeed;
    }

    if (m_y <= -1.0 || m_y >= 1.0) {
      m_yspeed = -m_yspeed;
    }

  }

}
