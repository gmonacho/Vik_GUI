//
// Created by gal on 16/04/19.
//

#include "VRA_Line.h"

VRA_Line::VRA_Line(int x1, int y1, int x2, int y2) : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

VRA_Line::VRA_Line(const VRA_Point &p1, const VRA_Point &p2) : m_x1(p1.getX()),
															   m_y1(p1.getY()),
															   m_x2(p2.getX()),
															   m_y2(p2.getY()) {}

VRA_Point VRA_Line::getP1() const
{
	VRA_Point   newPoint{m_x1, m_y1};
	return (newPoint);
}

VRA_Point VRA_Line::getP2() const
{
	VRA_Point   newPoint{m_x2, m_y2};
	return (newPoint);
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

