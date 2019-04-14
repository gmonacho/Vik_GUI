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

VRA_Rect::VRA_Rect(int x, int y, int w, int h) : m_sdlRect((SDL_Rect){x, y, w, h}) {}

VRA_Rect::~VRA_Rect() {}

const SDL_Rect &VRA_Rect::getSdlRect() const
{
	return (m_sdlRect);
}

const int   &VRA_Rect::getLeft() const
{
	return (m_sdlRect.x);
}

int         VRA_Rect::getRight() const
{
	return (m_sdlRect.x + m_sdlRect.w);
}

const int   &VRA_Rect::getTop() const
{
	return (m_sdlRect.y);
}

int         VRA_Rect::getBot() const
{
	return (m_sdlRect.y + m_sdlRect.h);
}

bool        VRA_Rect::hasRectIntersection(const VRA_Rect &rect)
{
	return (rect.getLeft() > m_sdlRect.x &&
			rect.getRight() < m_sdlRect.x + m_sdlRect.w &&
			rect.getTop() > m_sdlRect.y &&
			rect.getBot() < m_sdlRect.y + m_sdlRect.h);
}



