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

#include <optional>
#include <SDL_render.h>
#include "VRA_Window.h"
#include "VRA_Rect.h"

class VRA_Texture;

class VRA_Renderer
{
public:
	explicit        VRA_Renderer(const VRA_Window   &window,
			                     bool               auto_choice,
			                     Uint32             sdl_flags);

	VRA_Renderer(VRA_Renderer&& rend) noexcept;
	VRA_Renderer&   operator=(VRA_Renderer&& rend) noexcept;

	VRA_Renderer(const VRA_Renderer& rend) = delete;
	VRA_Renderer&   operator=(const VRA_Renderer& rend) = delete;

	virtual         ~VRA_Renderer();

	void            setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void            clear();
	void            display();
	void            drawRect(const VRA_Rect &rect);
	void            drawTexture(const VRA_Texture &texture, const std::optional<VRA_Rect> &srcRect = std::nullopt,
	                            const std::optional<VRA_Rect> &dstRect = std::nullopt);
	SDL_Renderer    *getPtr() const;
	SDL_Rect        getSdlRect() const;

private:
	SDL_Renderer    *m_ptr; 

};

#endif //VIK_WRAP_VRA_RENDERER_H
