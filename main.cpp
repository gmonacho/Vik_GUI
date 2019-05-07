#include "SDL2/SDL.h"
#include "VRA_Init.h"
#include <iostream>
#include <VRA_Window.h>
#include <VRA_Renderer.h>
#include <VRA_Event.h>
#include <SDL_image.h>
#include <VRA_Texture.h>
#include <VRA_Point.h>
#include <VRA_Font.h>
#include <VRA_Exception.h>

using namespace std;

int     main(int ac, char **av)
{
//	try
//	{
//		VRA_Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
//	}
//	catch (VRA_Exception)
//	{
//		cout << VRA_Exception.get
//	}
    VRA_Window      win{"VRA_Test", 100, 100, 600, 600, SDL_WINDOW_SHOWN};
	VRA_Renderer    rend{win, true, SDL_RENDERER_ACCELERATED};
	VRA_Rect        rect{10, 10, 30, 30};
	VRA_Rect        testRect{50, 50, 100, 50};
	VRA_Rect        testRect2{200, 200, 100, 100};
	VRA_Event       event;
	bool            loop{true};
	VRA_Font        font{R"(C:\Users\Shadow\Documents\ViKoDe\Vik_Wrap\fast99.ttf)", 100};
	SDL_Color       color = (SDL_Color){255, 255, 255, 255};
	VRA_Texture     testTexture{rend, R"(C:\Users\Shadow\Documents\ViKoDe\Vik_Wrap\banana.png)"};
	VRA_Texture     text;

	text = font.renderText(rend, "MaBite", (SDL_Color){40, 40, 40, 250});
    while (loop)
    {
	    rend.setDrawColor(30, 30, 30, 255);
	    rend.clear();
    	event.update();
	    rend.drawTexture(testTexture, nullopt, nullopt);
	    rend.drawTexture(text, nullopt, testRect);
//	    cout << "texture ptr " << sdlTexture << endl;
//    	SDL_RenderCopy(rend.getPtr(), sdlTexture, nullptr, &testRect.getSdlRect());
//    	SDL_RenderCopy(rend.getPtr(), text.getPtr(), nullptr, &testRect.getSdlRect());
        if(event.getEvent().type == SDL_QUIT || event.isKeyPressed(SDL_SCANCODE_ESCAPE))
            loop = false;
        rend.display();
    }
    return (1);
}