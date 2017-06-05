//
//  Swarm.cpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 03/06/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#include "Swarm.hpp"

namespace testproject {

  Swarm::Swarm() {
    m_pParticles = new Particle[NPARTICLES];
  }
  
  Swarm::~Swarm() {
    delete [] m_pParticles;
  }

}
