//
// Created by gal on 29/03/19.
//

#ifndef VIK_WRAP_VRA_WINDOW_H
#define VIK_WRAP_VRA_WINDOW_H

#include <string>

class VRA_Window
{

public:
    VRA_Window();
    VRA_Window(const char* title,
               int         x,
               int         y,
               int         w,
               int         h,
               Uint32      flags);

    virtual ~VRA_Window();

private:
    SDL_Window      *a_ptr;
    std::string     a_title;
    int             a_x;
    int             a_y;
    int             a_w;
    int             a_h;


};


#endif //VIK_WRAP_VRA_WINDOW_H
