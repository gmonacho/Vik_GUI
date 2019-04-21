#include "SDL2/SDL.h"
#include "vik_wrap.h"
#include <iostream>
#include <VRA_Window.h>
#include <VRA_Renderer.h>
#include <VRA_Event.h>
#include <SDL_image.h>
#include <VRA_Texture.h>
#include <VRA_Point.h>
#include <VRA_Font.h>

using namespace std;

int     main()
{
	if (!(VRA_init(SDL_INIT_VIDEO, IMG_INIT_PNG)))
		cout << "vra_init failed\n";
    VRA_Window      win{"VRA_Test", 100, 100, 600, 600, SDL_WINDOW_SHOWN};
	VRA_Renderer    rend{win, true, SDL_RENDERER_ACCELERATED};
	VRA_Texture     testTexture{rend, "/home/gal/ViKoDe/Vik_Wrap/test.png"};
	VRA_Rect        rect{10, 10, 30, 30};
	VRA_Rect        testRect{50, 50, 100, 50};
	VRA_Rect        testRect2{200, 200, 100, 100};
	VRA_Event       event;
	VRA_Point       firstPoint{10, 10};
	VRA_Point       secondPoint{60, 50};
	VRA_Point       thirdPoint{};
	VRA_Line        line{};
	bool            loop{true};
	VRA_Font        font{"/home/gal/ViKoDe/Vik_Wrap/04B_30__.TTF", 20};
	SDL_Color       color = (SDL_Color){255, 255, 255, 255};
	VRA_Texture     text{font.renderText(rend, "testaiewufahaiuEWhfauiwehaiwuefhiweufhwuifeaw", color)};
	SDL_Texture     *sdlTexture;

//	sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), TTF_RenderText_Solid(font.getPtr(), "testtest", color));
	sdlTexture = font.renderText(rend, "testest", color).getPtr();
	thirdPoint = firstPoint + secondPoint;
	rect = rect + thirdPoint;
    while (loop)
    {
	    rend.setDrawColor(30, 30, 30, 255);
	    rend.clear();
    	event.update();
    	testTexture.rotate(0.1);
    	rend.drawTexture(testTexture, nullopt, testRect2);
	    rend.drawTexture(text, nullopt, testRect);
    	SDL_RenderCopy(rend.getPtr(), sdlTexture, nullptr, &testRect.getSdlRect());
        if(event.getEvent().type == SDL_QUIT || event.isKeyPressed(SDL_SCANCODE_ESCAPE))
            loop = false;
        rend.display();
    }
    return (1);
}