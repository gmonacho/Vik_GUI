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
