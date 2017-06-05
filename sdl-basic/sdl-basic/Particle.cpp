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
  }
  
  Particle::~Particle() {
    
  }


}
