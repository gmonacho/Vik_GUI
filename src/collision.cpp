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

#include "collision.h"
#include <cmath>
#include <stdexcept>
#include "Point.h"
#include "Rect.h"
#include "Circle.h"

namespace vra
{

bool    collisionPointRect(const vra::Point &point,
                           const vra::Rect &rect)
{
    return (point.getX() >= rect.getLeft() &&
            point.getX() <= rect.getRight() &&
            point.getY() >= rect.getTop() &&
            point.getY() <= rect.getBot());
}


bool    collisionPointCircle(const vra::Point &point,
                             const vra::Circle &circle)
{
    int     dist;

    dist = std::sqrt(std::pow(circle.getPosition().getX() - point.getX(), 2) +
                     std::pow(circle.getPosition().getY() - point.getY(), 2));

    return (dist <= circle.getRadius());
}

bool    collisionLineLine(const Line &l1, const Line &l2)
{
    Point   D, E;
    double  denom;
    int     t, u;

    D.setX(l1.getX2() - l1.getX1());
    D.setY(l1.getY2() - l1.getY1());
    E.setX(l2.getX2() - l2.getX1());
    E.setY(l2.getY2() - l2.getY1());
    denom = D.getX() * E.getY() - D.getY() * E.getX();

    if (denom == 0)
        throw(std::logic_error("echec calcul collision"));
    t = -(l1.getX1() * E.getY() - l2.getX1() * E.getY() - E.getX()
           * l1.getY1() + E.getX() * l2.getY1()) / denom;
    if (t < 0 || t >= 1)
        return (false);
    u = -(-D.getX() * l1.getY1() + D.getX() * l2.getY1() +
           D.getY() * l1.getX1() - D.getY() * l2.getX1()) / denom;
    if (u < 0 || u >= 1)
        return (false);
    return (true);
}

// bool    collisionPointPolygon(const vra::Point &point,
//                               const vra::Polygon &polygon)
// {

// }

}   //  namespace vra
