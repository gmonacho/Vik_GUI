//
// Created by gal on 14/04/19.
//

#include "VRA_Point.h"

VRA_Point::VRA_Point(int x, int y) : m_sdlPoint((SDL_Point){x, y}) {}


VRA_Point::~VRA_Point() = default;

VRA_Point &VRA_Point::operator+=(VRA_Point &point)
{
	m_sdlPoint.x += point.getX();
	m_sdlPoint.y += point.getY();
	return (*this);
}

VRA_Point &VRA_Point::operator-=(VRA_Point &point)
{
	m_sdlPoint.x -= point.getX();
	m_sdlPoint.y -= point.getY();
	return (*this);
}

const SDL_Point &VRA_Point::getSdlPoint() const
{
	return (m_sdlPoint);
}

const int &VRA_Point::getX() const
{
	return (m_sdlPoint.x);
}

void VRA_Point::setX(const int &x)
{
	m_sdlPoint.x = x;
}

const int &VRA_Point::getY() const
{
	return (m_sdlPoint.y);
}


void VRA_Point::setY(const int &y)
{
	m_sdlPoint.y = y;
}


bool operator==(const VRA_Point &firstPoint, const VRA_Point &secondPoint)
{
	return (firstPoint.getX() == secondPoint.getX() &&
			firstPoint.getY() == secondPoint.getY());
}

VRA_Point   operator+(const VRA_Point &firstPoint, const VRA_Point &secondPoint)
{
	VRA_Point   newPoint(firstPoint.getX() + secondPoint.getX(),
	                     firstPoint.getY() + secondPoint.getY());
	return (newPoint);
}

VRA_Point   operator-(const VRA_Point &firstPoint, const VRA_Point &secondPoint)
{
	VRA_Point   newPoint(firstPoint.getX() - secondPoint.getX(),
	                     firstPoint.getY() - secondPoint.getY());
	return (newPoint);
}

