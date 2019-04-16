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

#ifndef VIK_WRAP_VRA_LINE_H
#define VIK_WRAP_VRA_LINE_H


#include "VRA_Point.h"

class VRA_Line
{
public:
	VRA_Line(int x1, int y1, int x2, int y2);

	VRA_Line(const VRA_Point &p1, const VRA_Point &p2);

	VRA_Line    &operator+=(const VRA_Point &point);
	VRA_Line    &operator-=(const VRA_Point &point);

	VRA_Point   getP1() const;
	void        setP1(const int &x, const int &y);

	VRA_Point   getP2() const;
	void        setP2(const int &x, const int &y);

	const int   &getX1() const;
	const int   &getY1() const;
	const int   &getX2() const;
	const int   &getY2() const;

private:
	int     m_x1;
	int     m_y1;
	int     m_x2;
	int     m_y2;
};


#endif //VIK_WRAP_VRA_LINE_H
