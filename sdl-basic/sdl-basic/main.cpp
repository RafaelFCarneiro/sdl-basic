//
//  main.cpp
//  sdl-basic
//
//  Created by RAFAEL F CARNEIRO on 28/05/17.
//  Copyright © 2017 RAFAEL F CARNEIRO. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL init failed." << std::endl;
        return 1;
    }
    
    std::cout << "SDL Init succeeded." << std::endl;
    
    SDL_Quit();
    
    return 0;
}
