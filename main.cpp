#include "SDL2/SDL.h"
#include "vik_wrap.h"
#include <iostream>
#include <VRA_Window.h>
#include <VRA_Renderer.h>
#include <VRA_Event.h>

using namespace std;

int     main()
{
	if (!(VRA_init(SDL_INIT_VIDEO)))
		cout << "vra_init failed\n";
    VRA_Window      win("VRA_Test", 100, 100, 600, 600, SDL_WINDOW_SHOWN);
	VRA_Renderer    rend(win, true, SDL_RENDERER_ACCELERATED);
	SDL_Event       sdl_event;
	VRA_Event       event;
	bool             loop{true};

	rend.setDrawColor(0, 255, 255, 255);
    rend.clear();
    while (loop)
    {
        event.update();
        SDL_WaitEvent(&sdl_event);
        if(sdl_event.type == SDL_QUIT || event.isKeyPressed(SDL_SCANCODE_ESCAPE))
            loop = false;
        rend.display();
    }
    return (1);
}