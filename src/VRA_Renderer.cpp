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

#include <iostream>
#include <optional>
#include "VRA_Window.h"
#include "VRA_Renderer.h"
#include "VRA_Texture.h"

VRA_Renderer::VRA_Renderer(const VRA_Window& window,
                           bool         autoChoice,
                           Uint32      sdl_flags)
{
	int     index = (autoChoice) ? -1 : 0;

	if ((m_ptr = SDL_CreateRenderer(window.getPtr(), index, sdl_flags)) == nullptr)
		throw std::bad_alloc();
}

VRA_Renderer::VRA_Renderer(VRA_Renderer &&rend) noexcept : m_ptr(rend.m_ptr)
{
	rend.m_ptr = nullptr;
}

VRA_Renderer &VRA_Renderer::operator=(VRA_Renderer &&rend) noexcept
{
	if (m_ptr)
		SDL_DestroyRenderer(m_ptr);
	m_ptr = rend.m_ptr;
	rend.m_ptr = nullptr;
	return (*this);
}

VRA_Renderer::~VRA_Renderer()
{
	if (m_ptr)
		SDL_DestroyRenderer(m_ptr);
}

SDL_Renderer *VRA_Renderer::getPtr() const
{
	return m_ptr;
}

SDL_RendererInfo VRA_Renderer::getInfo() const
{
	SDL_RendererInfo    renderInfo;

	SDL_GetRendererInfo(m_ptr, &renderInfo);
	return (renderInfo);
}

SDL_Rect VRA_Renderer::getSdlRect() const
{
	int     w;
	int     h;

	SDL_GetRendererOutputSize(m_ptr, &w, &h);
	return ((SDL_Rect){0, 0, w, h});
}

void VRA_Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(m_ptr, r, g, b, a);
}

SDL_Color VRA_Renderer::getDrawColor()
{
	SDL_Color   drawColor;

	SDL_GetRenderDrawColor(m_ptr, &drawColor.r, &drawColor.g, &drawColor.b, &drawColor.a);
	return (drawColor);
}

void VRA_Renderer::setTarget(const std::optional<VRA_Texture> &texture)
{
	SDL_SetRenderTarget(m_ptr, texture ? texture->getPtr() : nullptr);
}

void VRA_Renderer::setDrawBlendMode(SDL_BlendMode sdlBlendMode)
{
	SDL_SetRenderDrawBlendMode(m_ptr, sdlBlendMode);
}

SDL_BlendMode VRA_Renderer::getDrawBlendMode()
{
	SDL_BlendMode   sdlBlendMode;

	SDL_GetRenderDrawBlendMode(m_ptr, &sdlBlendMode);
	return (sdlBlendMode);
}

void VRA_Renderer::setViewport(const VRA_Rect &rect)
{
	SDL_RenderSetViewport(m_ptr, &rect.getSdlRect());
}

VRA_Rect VRA_Renderer::getViewport() const
{
	VRA_Rect    rect{};
	SDL_Rect    sdlRect;

	SDL_RenderGetViewport(m_ptr, &sdlRect);
	rect.setSdlRect(sdlRect);
	return (rect);
}

void VRA_Renderer::clear()
{
	SDL_RenderClear(m_ptr);
}

void VRA_Renderer::display()
{
	SDL_RenderPresent(m_ptr);
}

void VRA_Renderer::drawPoint(const VRA_Point &point)
{
	SDL_RenderDrawPoint(m_ptr, point.getX(), point.getY());
}

void VRA_Renderer::drawLine(const VRA_Line &line)
{
	SDL_RenderDrawLine(m_ptr, line.getX1(), line.getY1(), line.getX2(), line.getY2());
}

void VRA_Renderer::drawRect(const VRA_Rect &rect)
{
	SDL_RenderDrawRect(m_ptr, &rect.getSdlRect());
}

void VRA_Renderer::fillRect(const VRA_Rect &rect)
{
	SDL_RenderFillRect(m_ptr, &rect.getSdlRect());
}

void VRA_Renderer::drawTexture(const VRA_Texture &texture,
							   const std::optional<VRA_Rect> &srcRect,
							   const std::optional<VRA_Rect> &dstRect)
{
	if (texture.getFlip() == SDL_FLIP_NONE && texture.getAngle() == 0)
		SDL_RenderCopy(m_ptr, texture.getPtr(),
					   srcRect ? &srcRect->getSdlRect() : nullptr,
					   dstRect ? &dstRect->getSdlRect() : nullptr);
	else
	{
		std::cout  << texture.getFlip();
		SDL_RenderCopyEx(m_ptr,
				         texture.getPtr(),
				         srcRect ? &srcRect->getSdlRect() : nullptr,
		                 dstRect ? &dstRect->getSdlRect() : nullptr,
		                 texture.getAngle(),
		                 &texture.getCenter().getSdlPoint(),
		                 texture.getFlip());
	}
}











