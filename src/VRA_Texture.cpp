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

#include <string>
#include <SDL_image.h>
#include <iostream>
#include "VRA_Texture.h"
#include "VRA_Renderer.h"



VRA_Texture::VRA_Texture() : m_ptr(nullptr), m_flip(SDL_FLIP_NONE), m_center(VRA_Point{}), m_angle(0){}

VRA_Texture::VRA_Texture(SDL_Texture *sdlTexture) : m_ptr(sdlTexture), m_flip(SDL_FLIP_NONE), m_center(VRA_Point{}), m_angle(0){}

VRA_Texture::VRA_Texture(const VRA_Renderer &rend, const std::string &file) : m_flip(SDL_FLIP_NONE),
																			  m_center(VRA_Point{}),
																			  m_angle(0)
{
	SDL_Surface     *tmp;
	const char      *tmpStr;
	int             w;
	int             h;

	tmpStr = file.c_str();
	tmp = IMG_Load(tmpStr);
	if (!tmp)
	{
		std::cout << SDL_GetError() << std::endl;
		throw (std::bad_alloc());
	}
	if (!(m_ptr = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
	{
		std::cout << SDL_GetError() << std::endl;
		throw (std::bad_alloc());
	}
	SDL_QueryTexture(m_ptr, nullptr, nullptr, &w, &h);
}

VRA_Texture::VRA_Texture(const VRA_Renderer &rend, Uint32 format, int access, int w, int h) : m_flip(SDL_FLIP_NONE), m_center(VRA_Point{w / 2, h / 2}), m_angle(0)
{
	m_ptr = SDL_CreateTexture(rend.getPtr(), format,access, w, h);
	if (!m_ptr)
		throw (std::bad_alloc());
}

VRA_Texture::~VRA_Texture()
{
	if (m_ptr)
		SDL_DestroyTexture(m_ptr);
}

VRA_Texture &VRA_Texture::update(const std::optional<VRA_Rect> &rect, const void *pixels, const int &pitch)
{
	SDL_UpdateTexture(m_ptr, rect ? &rect->getSdlRect() : nullptr, pixels, pitch);
	return (*this);
}

SDL_Texture *VRA_Texture::getPtr() const
{
	return m_ptr;
}

SDL_Rect VRA_Texture::getSdlRect() const
{
	int     w;
	int     h;

	SDL_QueryTexture(nullptr, nullptr, nullptr, &w, &h);
	return ((SDL_Rect){0, 0, w, h});
}


const SDL_RendererFlip &VRA_Texture::getFlip() const
{
	return (m_flip);
}

void VRA_Texture::setFlip(const SDL_RendererFlip &flip)
{
	m_flip = flip;
}

const double &VRA_Texture::getAngle() const
{
	return (m_angle);
}

void VRA_Texture::rotate(const double &angle)
{
	m_angle += angle;
}

const VRA_Point& VRA_Texture::getCenter() const
{
	return (m_center);
}

void VRA_Texture::setCenter(const VRA_Point& center)
{
	m_center = center;
}

void VRA_Texture::setBlendMode(const SDL_BlendMode &blendMode)
{
	SDL_SetTextureBlendMode(m_ptr, blendMode);
}

void VRA_Texture::setColorMod(const Uint8 &r, const Uint8 &g, const Uint8 &b)
{
	SDL_SetTextureColorMod(m_ptr, r, g, b);
}

SDL_BlendMode VRA_Texture::getBlendMode() const
{
	SDL_BlendMode   blendMode;

	SDL_GetTextureBlendMode(m_ptr, &blendMode);
	return (blendMode);
}

SDL_Color VRA_Texture::getColorMod() const
{
	SDL_Color   colorMod;

	SDL_GetTextureColorMod(m_ptr, &colorMod.r, &colorMod.g, &colorMod.b);
	return  (colorMod);
}

void VRA_Texture::setAlphaMod(const Uint8 &alpha)
{
	SDL_SetTextureAlphaMod(m_ptr, alpha);
}

Uint8 VRA_Texture::GetAlphaMod() const
{
	Uint8   alpha;

	SDL_GetTextureAlphaMod(m_ptr, &alpha);
	return 0;
}




