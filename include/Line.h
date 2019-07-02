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

#ifndef LINE_H_
#define LINE_H_

#include "GeometricObject.h"
#include "Point.h"


namespace vra
{

class Line : public GeometricObject
{
 public:
    /**
     * Construct an set all the value (x1, x2, y1, y2) to 0.
     */
    Line();

    /**
     * Construct from given values
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     */
    Line(int x1, int y1, int x2, int y2);

    /**
     * Construct from given points
     * @param p1
     * @param p2
     */
    Line(const Point &p1, const Point &p2);

    /**
     * add the point values to the line's points values
     * @param point
     * @return The addition result
     */
    Line &operator+=(const Point &point) override;

    /**
     * subs the point values to the line's points values
     * @param point
     * @return The substraction result
     */
    Line &operator-=(const Point &point) override;

    Line &move(const int &dx, const int &dy) override;

    /**
     * get the line's first point (x1, y1).
     * @return P1 (x1, y1)
     */
    Point getP1() const;

    /**
     * set the line's first point (x1, y1) value
     * @param x
     * @param y
     */
    Line &setP1(const int &x, const int &y);

    /**
     * get the line's second point (x2, y12).
     * @return P2 (x2, y2)
     */
    Point getP2() const;

    /**
     * set the line's second point (x2, y2) value
     * @param x
     * @param y
     */
    Line &setP2(const int &x, const int &y);

    /**
     *
     * @return x1
     */
    const int &getX1() const;

    /**
     *
     * @return y1
     */
    const int &getY1() const;

    /**
     *
     * @return x2
     */
    const int &getX2() const;

    /**
     *
     * @return y2
     */
    const int &getY2() const;

 private:
    int m_x1;
    int m_y1;
    int m_x2;
    int m_y2;
};
}   //  namespace vra

#endif  //   LINE_H_
