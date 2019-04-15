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

#ifndef VIK_WRAP_VRA_RENDERER_H
#define VIK_WRAP_VRA_RENDERER_H

#include <SDL_render.h>
#include <optional>
#include "VRA_Window.h"
#include "VRA_Rect.h"
#include "VRA_Point.h"
#include "VRA_Line.h"

class VRA_Texture;

class VRA_Renderer
{
public:
	explicit        VRA_Renderer(const VRA_Window   &window,
			                     bool               autoChoice,
			                     Uint32             sdl_flags);

	VRA_Renderer(VRA_Renderer&& rend) noexcept;
	VRA_Renderer&   operator=(VRA_Renderer&& rend) noexcept;

	VRA_Renderer(const VRA_Renderer& rend) = delete;
	VRA_Renderer&   operator=(const VRA_Renderer& rend) = delete;

	virtual             ~VRA_Renderer();

	SDL_Renderer        *getPtr() const;

	SDL_RendererInfo    getInfo() const;

	SDL_Rect            getSdlRect() const;

	void                setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	SDL_Color           getDrawColor();

	void                setTarget(const std::optional<VRA_Texture> &texture);

	void                setDrawBlendMode(SDL_BlendMode sdlBlendMode);
	SDL_BlendMode       getDrawBlendMode();

	void                clear();

	void                display();

	void                drawTextureSdl(const VRA_Texture &texture,
									const std::optional<SDL_Rect> &srcRect,
		                            const std::optional<SDL_Rect> &dstRect);

	void                drawTexture(const VRA_Texture &texture,
									const std::optional<VRA_Rect> &srcRect,
		                            const std::optional<VRA_Rect> &dstRect);

	void                drawPoint(const VRA_Point &point);

	void                drawLine(const VRA_Line &line);

	void                drawRect(const VRA_Rect &rect);
	void                fillRect(const VRA_Rect &rect);

private:
	SDL_Renderer    *m_ptr; 

};

#endif //VIK_WRAP_VRA_RENDERER_H
