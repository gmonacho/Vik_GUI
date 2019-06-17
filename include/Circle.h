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

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Point.h"

namespace vra
{

class Circle
{
 private:
    vra::Point  m_position;
    int         m_radius;

 public:
    Circle(const int &x, const int &y, const int &radius);

    ~Circle() = default;

    Circle &operator+=(const Point &point);

    Circle &operator-=(const Point &point);

    Circle &setPosition(const int &x, const int &y);

    const vra::Point &getPosition() const;

    Circle &setRadius(const int &radius);

    const int &getRadius() const;
};

bool    operator==(const Circle &firstCircle, const Circle &secondCircle);

Circle  operator+(const Circle &circle, const Point &point);

Circle  operator-(const Circle &circle, const Point &point);

}   //  namespace vra

#endif  //  CIRCLE_H_
