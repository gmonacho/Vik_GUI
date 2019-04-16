//
// Created by gal on 16/04/19.
//

#ifndef VIK_WRAP_VRA_LINE_H
#define VIK_WRAP_VRA_LINE_H


#include "VRA_Point.h"

class VRA_Line
{
public:
	VRA_Line(int x1, int y1, int x2, int y2);

	VRA_Line(const VRA_Point &p1, const VRA_Point &p2);

	VRA_Line    &operator+=(const VRA_Point &point);

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
