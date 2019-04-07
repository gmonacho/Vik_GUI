//
// Created by gal on 29/03/19.
//

#include "SDL2/SDL.h"
#include "vik_wrap.h"

int     VRA_init(Uint32 flags)
{
    if (SDL_Init(flags) < 0)
        return (0);
    return (1);
}
