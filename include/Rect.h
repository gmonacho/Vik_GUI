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

#ifndef VIK_WRAP_RECT_H
#define VIK_WRAP_RECT_H


#include <SDL_rect.h>
#include "Point.h"


namespace vra {

	class Rect {
	public:
		explicit Rect(int x = 0, int y = 0, int w = 0, int h = 0);

		virtual         ~Rect();

		Rect &operator+=(const Point &point);

		Rect &operator-=(const Point &point);

		const SDL_Rect &getSdlRect() const;

		void setSdlRect(const SDL_Rect &rect);

		const int &getLeft() const;

		int getRight() const;

		const int &getTop() const;

		int getBot() const;

		const int &getX() const;

		const int &getY() const;

		const int &getW() const;

		const int &getH() const;

		bool hasRectIntersection(const Rect &rect);

	private:
		SDL_Rect m_sdlRect;
	};

	bool operator==(const Rect &firstRect, const Rect &secondRect);

	Rect operator+(const Rect &firstRect, const Rect &secondRect);

	Rect operator-(const Rect &firstRect, const Rect &secondRect);


	Rect operator+(const Rect &rect, const Point &point);

	Rect operator-(const Rect &rect, const Point &point);

}

#endif //VIK_WRAP_RECT_H