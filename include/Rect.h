/*
Copyright (c) 2019 Gael Monachon

Permission is hereby granted, free of charge, to any person obtaining a copy
        of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
        to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
        copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
        copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
        AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef RECT_H_
#define RECT_H_


#include <SDL_rect.h>
#include "GeometricObject.h"
#include "Point.h"


namespace vra
{
class Rect : public GeometricObject
{
 public:
    /**
     * @brief   Construct and initialize values to 0
     */
    explicit Rect(int x = 0, int y = 0, int w = 0, int h = 0);

    /**
     * @brief   Destructor
     */
    virtual         ~Rect();

    /**
     * @brief   addition between to Point object (x + x, y + y)=
     */
    Rect &operator+=(const Point &point) override;

    /**
     * @brief   substraction between to Point object (x - x, y - y)=
     */
    Rect &operator-=(const Point &point) override;

    Rect &move(const int &dx, const int &dy) override;

    /**
     * @brief   get the Rect's sdl struct
     * @return  the SDL_Rect struct
     */
    const SDL_Rect &getSdlRect() const;

    /**
     * @brief   set the Rect's sdl struct
     * @param   rect : SDL_Rect struct
     */
    Rect &setSdlRect(const SDL_Rect &rect);

    /**
     * @brief   get the rect's left side x position
     */
    const int &getLeft() const;

    /**
     * @brief   get the rect's right side x position
     */
    int getRight() const;

    /**
     * @brief   get the rect's top side y position
     */
    const int &getTop() const;

    /**
     * @brief   get the rect's left side y position
     */
    int getBot() const;

    /**
     * @brief   get the rect's x position
     */
    const int &getX() const;

    /**
     * @brief   get the rect's y position
     */
    const int &getY() const;

    /**
     * @brief   get the rect's width
     */
    const int &getW() const;

    /**
     * @brief   get the rect's height
     */
    const int &getH() const;

    /**
     * @brief   test if the rect has an intersection with an other rect
     * @param   other Rect
     * @return  true or false
     */
    bool hasRectIntersection(const Rect &rect);

 private:
    SDL_Rect m_sdlRect;
};

bool operator==(const Rect &firstRect, const Rect &secondRect);

Rect operator+(const Rect &firstRect, const Rect &secondRect);

Rect operator-(const Rect &firstRect, const Rect &secondRect);


Rect operator+(const Rect &rect, const Point &point);

Rect operator-(const Rect &rect, const Point &point);

}   //  namespace vra

#endif  //  RECT_H_
