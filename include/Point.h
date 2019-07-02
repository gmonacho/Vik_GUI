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

#ifndef POINT_H_
#define POINT_H_


#include <SDL_rect.h>
#include "GeometricObject.h"

namespace vra
{

class Point : public GeometricObject
{
 public:
    /**
     * construct the given values, x = 0 and y = 0 if no values are given
     * @param x
     * @param y
     */
    explicit Point(int x = 0, int y = 0);

    Point &operator+=(const Point &point) override;

    Point &operator-=(const Point &point) override;

    Point &move(const int &dx, const int &dy) override;

    /**
     * get the point's sdl structure
     * @return point's sdl structure
     */
    const SDL_Point &getSdlPoint() const;

    /**
     * get the point's x value
     * @return point's x value
     */
    const int &getX() const;

    /**
     * set the point's x value
     * @param x value
     */
    Point &setX(const int &x);

    /**
     * get the point's y value
     * @return point's y value
     */
    const int &getY() const;

    /**
     * set the point's y value
     * @param point's y value
     */
    Point &setY(const int &y);

    virtual     ~Point();

 private:
    SDL_Point m_sdlPoint;
};

bool operator==(const Point &firstPoint, const Point &secondPoint);

bool operator!=(const Point &firstPoint, const Point &secondPoint);

Point operator+(const Point &firstPoint, const Point &secondPoint);

Point operator-(const Point &firstPoint, const Point &secondPoint);

}   //  namespace vra

#endif  //  POINT_H_
