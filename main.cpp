#include "SDL2/SDL.h"
#include "vik_wrap.h"
#include <iostream>
#include <VRA_Window.h>
#include <VRA_Renderer.h>

using namespace std;

int     main()
{
	if (!(VRA_init(SDL_INIT_VIDEO)))
		cout << "vra_init failed\n";
    VRA_Window      win("VRA_Test", 100, 100, 600, 600, SDL_WINDOW_SHOWN);
	VRA_Renderer    rend(win, true, SDL_RENDERER_ACCELERATED);
	SDL_Event       event;
	int             loop;

    rend.setDrawColor(0, 255, 255, 255);
    rend.clear();
    loop = SDL_TRUE;
    while (loop)
    {
        SDL_PumpEvents();
        SDL_WaitEvent(&event);
        if(event.type == SDL_QUIT)
            loop = SDL_FALSE;
        rend.display();
    }
    return (1);
}