#include "SDL.h"
#include "Init.h"
#include <iostream>
#include <Window.h>
#include <Renderer.h>
#include <Event.h>
#include <SDL_image.h>
#include <Texture.h>
#include <Point.h>
#include <Font.h>
#include <Exception.h>

using namespace std;
using namespace vra;

int     main(int ac, char **av)
{
	Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
    vra::Window			window{"VRA_Test", 100, 100, 600, 600, SDL_WINDOW_SHOWN};
	vra::Renderer		renderer{window, true, SDL_RENDERER_ACCELERATED};
	vra::Event			event{};
	bool				loop{true};

	while (loop)
	{
		renderer.setDrawColor(50, 50, 50, 255);
		renderer.clear();
		event.waitEvent();
        if(event.getEvent().type == SDL_QUIT || event.isKeyPressed(SDL_SCANCODE_ESCAPE))
            loop = false;
        renderer.draw();
    }
    return (1);
}