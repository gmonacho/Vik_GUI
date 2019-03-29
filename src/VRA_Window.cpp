//
// Created by gal on 29/03/19.
//

#include "SDL2/SDL.h"
#include "VRA_Window.h"


VRA_Window::VRA_Window() {}

VRA_Window::VRA_Window(const char* title,
                       int         x,
                       int         y,
                       int         w,
                       int         h,
                       Uint32      flags) :
                       a_title(title),
                       a_x(x),
                       a_y(y),
                       a_w(w),
                       a_h(h)
{
    a_ptr = SDL_CreateWindow(title, x, y, w, h, flags);
}

VRA_Window::~VRA_Window()
{
    SDL_DestroyWindow(a_ptr);
}
