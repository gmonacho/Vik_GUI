#include "SDL2/SDL.h"
#include "vik_wrap.h"
#include <iostream>
#include <VRA_Window.h>

int     main()
{
    SDL_Event   event;
    VRA_Window  window;
    int         loop;

    if (!(vra_init(SDL_INIT_VIDEO)))
        std::cout << "vra_init failed\n";
    window = VRA_Window("Vik_Wrap", 100, 100, 500, 500, SDL_WINDOW_SHOWN);
    loop = SDL_TRUE;
    while (loop)
    {
        SDL_PumpEvents();
        SDL_WaitEvent(&event);
        if(event.type == SDL_QUIT)
            loop = SDL_FALSE;
    }
    return (1);
}