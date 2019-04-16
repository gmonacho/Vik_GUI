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



VRA_Texture::VRA_Texture() : m_ptr(nullptr) {}

VRA_Texture::VRA_Texture(const VRA_Renderer &rend, const std::string &file)
{
	SDL_Surface     *tmp;
	const char      *tmpStr;

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
}

VRA_Texture::VRA_Texture(const VRA_Renderer &rend, Uint32 format, int access, int w, int h)
{
	m_ptr = SDL_CreateTexture(rend.getPtr(), format,access, w, h);
	if (!m_ptr)
		throw (std::bad_alloc());
}

VRA_Texture &VRA_Texture::operator=(VRA_Texture &&texture) noexcept
{
	if (m_ptr)
		SDL_DestroyTexture(m_ptr);
	m_ptr = texture.m_ptr;
	texture.m_ptr = nullptr;
	return (*this);
}


VRA_Texture::~VRA_Texture()
{
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

void VRA_Texture::setBlendMode(const SDL_BlendMode &blendMode)
{
	SDL_SetTextureBlendMode(m_ptr, blendMode);
}

void VRA_Texture::setColorMod(const Uint8 &r, const Uint8 &g, const Uint8 &b)
{
	SDL_SetTextureColorMod(m_ptr, r, g, b);
}

SDL_BlendMode VRA_Texture::getBlendMode()
{
	SDL_BlendMode   blendMode;

	SDL_GetTextureBlendMode(m_ptr, &blendMode);
	return (blendMode);
}

SDL_Color VRA_Texture::getColorMod()
{
	SDL_Color   colorMod;

	SDL_GetTextureColorMod(m_ptr, &colorMod.r, &colorMod.g, &colorMod.b);
	return  (colorMod);
}

void VRA_Texture::setAlphaMod(const Uint8 &alpha)
{
	SDL_SetTextureAlphaMod(m_ptr, alpha);
}

Uint8 VRA_Texture::GetAlphaMod()
{
	Uint8   alpha;

	SDL_GetTextureAlphaMod(m_ptr, &alpha);
	return 0;
}





