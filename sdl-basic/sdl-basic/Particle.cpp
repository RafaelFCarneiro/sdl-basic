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
    this->init();
  }
  
  Particle::~Particle() {}
  
  void Particle::init() {
    m_x = 0;
    m_y = 0;
    m_direction =  (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.019 * rand())/RAND_MAX;
    m_speed *= m_speed;
  }
  
  void Particle::update(int interval) {
    m_direction += interval*0.0006;
    
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);
    
    m_x += xspeed * interval;
    m_y += yspeed * interval;
    
    if (m_x < -1 || m_x > 1 || m_y < -1 || m_y >1) {
      this->init();
    }
    
    if (rand() < RAND_MAX/100) {
      this->init();
    }
  }
}
