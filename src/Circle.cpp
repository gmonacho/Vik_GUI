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

#include "Circle.h"
#include "Point.h"

namespace vra
{

Circle::Circle(const int &x, const int &y, const int &radius) :
               m_position(Point{x, y}), m_radius(radius) {}



Circle &Circle::operator+=(const Point &point)
{
    Circle::setPosition(Circle::getPosition().getX() + point.getX(),
                        Circle::getPosition().getY() + point.getY());
}

Circle &Circle::operator-=(const Point &point)
{
    Circle::setPosition(Circle::getPosition().getX() - point.getX(),
                        Circle::getPosition().getY() - point.getY());
}

Circle &Circle::setPosition(const int &x, const int &y)
{
    m_position.setX(x);
    m_position.setY(y);
    return (*this);
}

const vra::Point &Circle::getPosition() const
{
    return (m_position);
}

Circle &Circle::setRadius(const int &radius)
{
    if (radius >= 0)
        m_radius = radius;
    return (*this);
}

const int &Circle::getRadius() const
{
    return (m_radius);
}

bool operator==(const Circle &firstCircle, const Circle &secondCircle)
{
    return (firstCircle.getPosition() == secondCircle.getPosition() &&
            firstCircle.getRadius() == secondCircle.getRadius());
}

Circle  operator+(const Circle &circle, const Point &point)
{
    return (Circle{circle.getPosition().getX() + point.getX(),
                   circle.getPosition().getY() + point.getY(),
                   circle.getRadius()});
}

Circle  operator-(const Circle &circle, const Point &point)
{
    return (Circle{circle.getPosition().getX() - point.getX(),
                   circle.getPosition().getY() - point.getY(),
                   circle.getRadius()});
}

}   //  namespace vra
