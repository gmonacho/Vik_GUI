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

#ifndef VIK_WRAP_POINT_H
#define VIK_WRAP_POINT_H


#include <SDL_rect.h>

namespace vra {

	class Point {
	public:
		explicit Point(int x = 0, int y = 0);

		Point &operator+=(Point &point);

		Point &operator-=(Point &point);

		const SDL_Point &getSdlPoint() const;

		const int &getX() const;

		void setX(const int &x);

		const int &getY() const;

		void setY(const int &y);

		virtual     ~Point();

	private:
		SDL_Point m_sdlPoint;
	};

	bool operator==(const Point &firstPoint, const Point &secondPoint);

	Point operator+(const Point &firstPoint, const Point &secondPoint);

	Point operator-(const Point &firstPoint, const Point &secondPoint);

}

#endif //VIK_WRAP_POINT_H
