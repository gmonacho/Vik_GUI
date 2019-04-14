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

#ifndef VIK_WRAP_VRA_RECT_H
#define VIK_WRAP_VRA_RECT_H


#include <SDL_rect.h>

class VRA_Rect
{
public:
	explicit    VRA_Rect();
	explicit    VRA_Rect(int x, int y, int w, int h);
	SDL_Rect    getSdlRect() const;
	const int   &getLeft() const;
	int         getRight() const;
	const int   &getTop() const;
	int         getBot() const;
	bool        hasRectIntersection(const VRA_Rect &rect);

private:
	int     m_x;
	int     m_y;
	int     m_w;
	int     m_h;

};


#endif //VIK_WRAP_VRA_RECT_H
