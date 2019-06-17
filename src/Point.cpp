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

#include "Point.h"

namespace vra
{

Point::Point(int x, int y) : m_sdlPoint((SDL_Point) {x, y}) {}


Point::~Point() = default;

Point &Point::operator+=(const Point &point)
{
    m_sdlPoint.x += point.getX();
    m_sdlPoint.y += point.getY();
    return (*this);
}

Point &Point::operator-=(const Point &point)
{
    m_sdlPoint.x -= point.getX();
    m_sdlPoint.y -= point.getY();
    return (*this);
}

const SDL_Point &Point::getSdlPoint() const
{
    return (m_sdlPoint);
}

const int &Point::getX() const
{
    return (m_sdlPoint.x);
}

Point &Point::setX(const int &x)
{
    m_sdlPoint.x = x;
    return (*this);
}

const int &Point::getY() const
{
    return (m_sdlPoint.y);
}


Point &Point::setY(const int &y)
{
    m_sdlPoint.y = y;
    return (*this);
}


bool operator!=(const Point &firstPoint, const Point &secondPoint)
{
    return (firstPoint.getX() != secondPoint.getX() ||
            firstPoint.getY() != secondPoint.getY());
}

bool operator==(const Point &firstPoint, const Point &secondPoint)
{
    return (firstPoint.getX() == secondPoint.getX() &&
            firstPoint.getY() == secondPoint.getY());
}

Point operator+(const Point &firstPoint, const Point &secondPoint)
{
    Point newPoint(firstPoint.getX() + secondPoint.getX(),
                    firstPoint.getY() + secondPoint.getY());
    return (newPoint);
}

Point operator-(const Point &firstPoint, const Point &secondPoint)
{
    Point newPoint(firstPoint.getX() - secondPoint.getX(),
                    firstPoint.getY() - secondPoint.getY());
    return (newPoint);
}

}   //  namespace vra
