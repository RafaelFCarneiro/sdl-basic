//
//  Swarm.hpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 03/06/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include <stdio.h>

#include "Particle.hpp"

namespace testproject {
  class Swarm {
  public:
    const static int NPARTICLES = 5000;
  
  private:
    Particle * m_pParticles;
    int m_lastTime;
    
  public:
    Swarm();
    virtual ~Swarm();
    
    void upadte(int elapsed);
    
    const Particle * const getParticles() { return m_pParticles; };
    
  };
}

#endif /* Swarm_hpp */
