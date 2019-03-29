//
// Created by gal on 29/03/19.
//

#ifndef VIK_WRAP_VRA_RENDERER_H
#define VIK_WRAP_VRA_RENDERER_H

#include "SDL2/SDL.h"

class VRA_Renderer {

public:
    VRA_Renderer(SDL_Window *ptr, int index, Uint32 flags);
private:
    SDL_Renderer    *a_ptr;
};


#endif //VIK_WRAP_VRA_RENDERER_H
