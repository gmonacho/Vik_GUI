//
// Created by gal on 29/03/19.
//

#include "VRA_Renderer.h"

VRA_Renderer::VRA_Renderer(SDL_Window *ptr, int index, Uint32 flags)
{
    a_ptr = SDL_CreateRenderer(ptr, index, flags);
}
