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

#include "VRA_Rect.h"


VRA_Rect::VRA_Rect() : m_x(0), m_y(0), m_w(0), m_h(0) {}

VRA_Rect::VRA_Rect(int x, int y, int w, int h) : m_x(x), m_y(y), m_w(w), m_h(h) {}

SDL_Rect    VRA_Rect::getSdlRect() const
{
	return ((SDL_Rect){m_x, m_y, m_w, m_h});
}

const int   &VRA_Rect::getLeft() const
{
	return (m_x);
}

int         VRA_Rect::getRight() const
{
	return (m_x + m_w);
}

const int   &VRA_Rect::getTop() const
{
	return (m_y);
}

int         VRA_Rect::getBot() const
{
	return (m_y + m_h);
}

bool        VRA_Rect::hasRectIntersection(const VRA_Rect &rect)
{
	return (rect.getLeft() > m_x && rect.getRight() < m_x + m_w && rect.getTop() > m_y && rect.getBot() < m_y + m_h);
}

