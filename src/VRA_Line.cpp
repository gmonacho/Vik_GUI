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

#include "VRA_Line.h"

VRA_Line::VRA_Line(int x1, int y1, int x2, int y2) : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

VRA_Line::VRA_Line(const VRA_Point &p1, const VRA_Point &p2) : m_x1(p1.getX()),
															   m_y1(p1.getY()),
															   m_x2(p2.getX()),
															   m_y2(p2.getY()) {}


VRA_Line &VRA_Line::operator+=(const VRA_Point &point)
{
	m_x1 += point.getX();
	m_y1 += point.getY();
	m_x2 += point.getX();
	m_y2 += point.getY();
	return (*this);
}

VRA_Line &VRA_Line::operator-=(const VRA_Point &point)
{
	m_x1 -= point.getX();
	m_y1 -= point.getY();
	m_x2 -= point.getX();
	m_y2 -= point.getY();
	return (*this);
}

VRA_Point VRA_Line::getP1() const
{
	VRA_Point   newPoint{m_x1, m_y1};
	return (newPoint);
}


void VRA_Line::setP1(const int &x, const int &y)
{
	m_x1 = x;
	m_y1 = y;
}

VRA_Point VRA_Line::getP2() const
{
	VRA_Point   newPoint{m_x2, m_y2};
	return (newPoint);
}

void VRA_Line::setP2(const int &x, const int &y)
{
	m_x2 = x;
	m_y2 = y;
}

const int &VRA_Line::getX1() const
{
	return (m_x1);
}

const int &VRA_Line::getY1() const
{
	return (m_x1);
}

const int &VRA_Line::getX2() const
{
	return (m_x2);
}

const int &VRA_Line::getY2() const
{
	return (m_y2);
}



