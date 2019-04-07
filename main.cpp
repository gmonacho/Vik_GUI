#include "SDL2/SDL.h"
#include "vik_wrap.h"
#include <iostream>
#include <VRA_Window.h>

int     main()
{
    SDL_Event       event;
    int             loop;
    VRA_Window      win;

    if (!(VRA_init(SDL_INIT_VIDEO)))
        std::cout << "vra_init failed\n";
    win = VRA_Window("VRA_Test", 100, 100, 600, 600, SDL_WINDOW_SHOWN);
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