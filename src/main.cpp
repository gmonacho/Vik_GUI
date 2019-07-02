
#include <vector>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Init.h"
#include "GeometricObject.h"
#include "Window.h"
#include "Renderer.h"
#include "Event.h"
#include "Texture.h"
#include "Point.h"
#include "Font.h"
#include "Exception.h"
#include "collision.h"
#include "Polygon.h"

static void test(const vra::GeometricObject &object)
{
    std::cout << "test\n";
}

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

    polygon.addPoint(vra::Point{200, 200});
    polygon.addPoint(vra::Point{400, 200});
    polygon.addPoint(vra::Point{100, 400});
    polygon.addPoint(vra::Point{40, 300});
    polygon.addPoint(vra::Point{160, 120});
    // polygon.addPoint(vra::Point{50, 150});
    test(circle);
    while (loop)
    {
        renderer.setDrawColor(50, 50, 50, 255);
        renderer.clear();
        // event.waitEvent();
        event.update();
        if (event.getEvent().type == SDL_QUIT ||
           event.isKeyPressed(SDL_SCANCODE_ESCAPE))
        {
            loop = false;
        }
        if (collisionPointPolygon(event.getMousePosition(), polygon) == true)
            std::cout << "collision\n";
        else
            std::cout << "pas collision\n";
        renderer.setDrawColor(200, 200, 200, 255);
        renderer.drawPolygon(polygon);
        renderer.draw();
    }
    return (1);
}
