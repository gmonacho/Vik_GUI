//
// Created by gal on 14/04/19.
//

#ifndef VIK_WRAP_VRA_POINT_H
#define VIK_WRAP_VRA_POINT_H


#include <SDL_rect.h>

class VRA_Point
{
public:
	explicit    VRA_Point(int x = 0, int y = 0);

	VRA_Point   &operator+=(VRA_Point   &point);
	VRA_Point   &operator-=(VRA_Point   &point);

	const SDL_Point &getSdlPoint() const;

	const int   &getX() const;
	void        setX(const int &x);

	const int   &getY() const;
	void        setY(const int &y);

	virtual     ~VRA_Point();

private:
	SDL_Point   m_sdlPoint;
};

bool        operator==(const VRA_Point &firstPoint, const VRA_Point &secondPoint);
VRA_Point   operator+(const VRA_Point &firstPoint, const VRA_Point &secondPoint);
VRA_Point   operator-(const VRA_Point &firstPoint, const VRA_Point &secondPoint);

#endif //VIK_WRAP_VRA_POINT_H
