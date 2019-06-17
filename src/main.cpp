#include "SDL.h"
#include "Init.h"
#include <iostream>
#include <vector>
#include <Window.h>
#include <Renderer.h>
#include <Event.h>
#include <SDL_image.h>
#include <Texture.h>
#include <Point.h>
#include <Font.h>
#include <Exception.h>
#include "collision.h"
#include "Polygon.h"

int     main(int ac, char **av)
{
    vra::Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
    vra::Window         window{"VRA_Test",
                               100, 100, 600, 600,
                               SDL_WINDOW_SHOWN};
    vra::Renderer       renderer{window, true, SDL_RENDERER_ACCELERATED};
    vra::Event          event{};
    vra::Rect           rect{200, 200, 200, 200};
    vra::Circle         circle{300, 300, 100};
    vra::Polygon        polygon;

    bool                loop{true};

    polygon.addPoint(vra::Point{100, 100});
    polygon.addPoint(vra::Point{200, 100});
    polygon.addPoint(vra::Point{50, 200});
    polygon.addPoint(vra::Point{20, 150});
    polygon.addPoint(vra::Point{80, 60});
    // polygon.addPoint(vra::Point{50, 150});
    while (loop)
    {
        renderer.setDrawColor(50, 50, 50, 255);
        renderer.clear();
        event.waitEvent();
        event.update();
        if (event.getEvent().type == SDL_QUIT ||
           event.isKeyPressed(SDL_SCANCODE_ESCAPE))
        {
            loop = false;
        }
        renderer.setDrawColor(200, 200, 200, 255);
        renderer.drawPolygon(polygon);
        renderer.draw();
    }
    return (1);
}
