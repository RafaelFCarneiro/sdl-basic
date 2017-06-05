//
//  Particle.hpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 03/06/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

namespace testproject {
  
  struct Particle {
    double m_x;
    double m_y;

    double m_xspeed;
    double m_yspeed;
    
  public:
    Particle();
    virtual ~Particle();
    
    void update();
  };

}

#endif /* Particle_hpp */
