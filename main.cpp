#include "SDL2/SDL.h"
#include "vik_wrap.h"
#include <iostream>
#include <VRA_Window.h>
#include <VRA_Renderer.h>
#include <VRA_Event.h>
#include <SDL_image.h>
#include <VRA_Texture.h>
#include <VRA_Point.h>

using namespace std;

int     main()
{
	if (!(VRA_init(SDL_INIT_VIDEO, IMG_INIT_PNG)))
		cout << "vra_init failed\n";
    VRA_Window      win{"VRA_Test", 100, 100, 600, 600, SDL_WINDOW_SHOWN};
	VRA_Renderer    rend{win, true, SDL_RENDERER_ACCELERATED};
	VRA_Texture     testTexture{rend, "/home/gal/ViKoDe/Vik_Wrap/test.png"};
	VRA_Rect        rect{10, 10, 30, 30};
	VRA_Rect        testRect{50, 50, 100, 100};
	SDL_Event       sdl_event;
	VRA_Event       event;
	VRA_Point       firstPoint{10, 10};
	VRA_Point       secondPoint{60, 50};
	VRA_Point       thirdPoint{};
	VRA_Line        line{firstPoint, secondPoint};
	bool            loop{true};

	thirdPoint = firstPoint + secondPoint;
	rect = rect + thirdPoint;
    while (loop)
    {
	    rend.setDrawColor(0, 255, 255, 255);
	    rend.clear();
    	event.update();
    	rend.setDrawColor(0, 0, 0, 255);
    	rend.drawLine(line);
    	rend.drawPoint(firstPoint);
    	rend.drawPoint(secondPoint);
    	rend.drawPoint(thirdPoint);
    	rend.drawRect(rect);
    	rend.drawTexture(testTexture, nullopt, testRect);
        if(sdl_event.type == SDL_QUIT || event.isKeyPressed(SDL_SCANCODE_ESCAPE))
            loop = false;
        rend.display();
    }
    return (1);
}