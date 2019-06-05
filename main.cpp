#include "SDL2/SDL.h"
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
    vra::Window      win{"VRA_Test", 100, 100, 600, 600, SDL_WINDOW_SHOWN};
	vra::Renderer    rend{win, true, SDL_RENDERER_ACCELERATED};
	Rect        rect{10, 10, 30, 30};
	Rect        testRect{50, 50, 100, 50};
	Rect        testRect2{200, 200, 100, 100};
	Event       event;
	bool            loop{true};
	Font        font{R"(C:\Users\Shadow\Documents\ViKoDe\Vik_Wrap\fast99.ttf)", 100};
	SDL_Color       color = (SDL_Color){255, 255, 255, 255};
	Texture     testTexture(rend, R"(C:\Users\Shadow\Documents\ViKoDe\Vik_Wrap\banana.png)");
	Texture     text;

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