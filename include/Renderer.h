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

#ifndef VIK_WRAP_RENDERER_H
#define VIK_WRAP_RENDERER_H

#include <SDL_render.h>
#include <optional>
#include "Window.h"
#include "Rect.h"
#include "Point.h"
#include "Line.h"
#include "Texture.h"

class Window;

namespace vra {

	class Renderer {
	public:

		explicit Renderer(const Window &window,
		                  bool autoChoice,
		                  Uint32 sdl_flags);

		Renderer(Renderer &&rend) noexcept;

		Renderer &operator=(Renderer &&rend) noexcept;

		virtual             ~Renderer();

		SDL_Renderer *getPtr() const;

		SDL_RendererInfo getInfo() const;

		SDL_Rect getSdlRect() const;

		void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

		SDL_Color getDrawColor();

		void setTarget(const std::optional<Texture> &texture);

		void setDrawBlendMode(SDL_BlendMode sdlBlendMode);

		SDL_BlendMode getDrawBlendMode();

		void setViewport(const Rect &rect);

		Rect getViewport() const;

//	void                *readPixels(const Rect &rect, Uint32 sdlFormat, const int &pitch);

		void clear();

		void display();

		void drawTexture(const Texture &texture,
		                 const std::optional<Rect> &srcRect,
		                 const std::optional<Rect> &dstRect);

		void drawPoint(const Point &point);

		void drawLine(const Line &line);

		void drawRect(const Rect &rect);

		void fillRect(const Rect &rect);

	private:
		SDL_Renderer *m_ptr;

	};

}

#endif //VIK_WRAP_RENDERER_H
