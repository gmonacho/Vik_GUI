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

#include "Rect.h"

namespace vra {

	Rect::Rect(int x, int y, int w, int h) : m_sdlRect((SDL_Rect) {x, y, w, h}) {}

	Rect::~Rect() = default;

	Rect &Rect::operator+=(const Point &point) {
		m_sdlRect.x += point.getX();
		m_sdlRect.y += point.getY();
		return (*this);
	}

	Rect &Rect::operator-=(const Point &point) {
		m_sdlRect.x -= point.getX();
		m_sdlRect.y -= point.getY();
		return (*this);
	}

	const SDL_Rect &Rect::getSdlRect() const {
		return (m_sdlRect);
	}

	const int &Rect::getLeft() const {
		return (m_sdlRect.x);
	}

	int Rect::getRight() const {
		return (m_sdlRect.x + m_sdlRect.w);
	}

	const int &Rect::getTop() const {
		return (m_sdlRect.y);
	}

	int Rect::getBot() const {
		return (m_sdlRect.y + m_sdlRect.h);
	}

	const int &Rect::getX() const {
		return (m_sdlRect.x);
	}

	const int &Rect::getY() const {
		return (m_sdlRect.y);
	}

	const int &Rect::getW() const {
		return (m_sdlRect.w);
	}

	const int &Rect::getH() const {
		return (m_sdlRect.h);
	}

	bool Rect::hasRectIntersection(const Rect &rect) {
		return (rect.getLeft() > m_sdlRect.x &&
		        rect.getRight() < m_sdlRect.x + m_sdlRect.w &&
		        rect.getTop() > m_sdlRect.y &&
		        rect.getBot() < m_sdlRect.y + m_sdlRect.h);
	}

	void Rect::setSdlRect(const SDL_Rect &rect) {
		m_sdlRect = rect;
	}

	bool operator==(const Rect &firstRect, const Rect &secondRect) {
		return (firstRect.getX() == secondRect.getX() &&
		        firstRect.getY() == secondRect.getY() &&
		        firstRect.getW() == secondRect.getW() &&
		        firstRect.getH() == secondRect.getH());
	}

	Rect operator+(const Rect &firstRect, const Rect &secondRect) {
		Rect newRect{firstRect.getX() + secondRect.getX(),
		             firstRect.getY() + secondRect.getY(),
		             firstRect.getW() + secondRect.getW(),
		             firstRect.getH() + secondRect.getH()};
		return (newRect);
	}

	Rect operator-(const Rect &firstRect, const Rect &secondRect) {
		Rect newRect{firstRect.getX() - secondRect.getX(),
		             firstRect.getY() - secondRect.getY(),
		             firstRect.getW() - secondRect.getW(),
		             firstRect.getH() - secondRect.getH()};
		return (newRect);
	}

	Rect operator+(const Rect &rect, const Point &point) {
		Rect newRect{rect.getX() + point.getX(),
		             rect.getY() + point.getY(),
		             rect.getW(),
		             rect.getH()};
		return (newRect);
	}

	Rect operator-(const Rect &rect, const Point &point) {
		Rect newRect{rect.getX() - point.getX(),
		             rect.getY() - point.getY(),
		             rect.getW(),
		             rect.getH()};
		return (newRect);
	}

}