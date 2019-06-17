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
#include <cassert>
#include "Exception.h"
#include "Texture.h"
#include "Renderer.h"

namespace vra {

Texture::Texture() :
            m_ptr(nullptr),
            m_flip(SDL_FLIP_NONE),
            m_center(Point{}),
            m_angle(0) {}

Texture::Texture(SDL_Texture *sdlTexture) :
            m_ptr(sdlTexture),
            m_flip(SDL_FLIP_NONE),
            m_center(Point{}),
            m_angle(0) {}

Texture::Texture(const Renderer &rend, const std::string &file) :
            m_flip(SDL_FLIP_NONE), m_center(Point{}), m_angle(0)
{
    SDL_Surface *tmp;
    const char *tmpStr;
    tmpStr = file.c_str();
    tmp = IMG_Load(tmpStr);
    if (!tmp)
        throw(Exception("IMG_Load"));
    if (!(m_ptr = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
        throw(Exception("SDL_CreateTextureFromSurface"));
}

Texture::Texture(const Renderer &rend,
                    Uint32 format,
                    int access,
                    int w,
                    int h) : m_flip(SDL_FLIP_NONE),
                                m_center(Point{w / 2, h / 2}),
                                m_angle(0)
{
    m_ptr = SDL_CreateTexture(rend.getPtr(), format, access, w, h);
    if (!m_ptr)
        throw(Exception("SDL_CreateTexture"));
}

Texture::Texture(Texture&& other) noexcept : m_ptr(other.m_ptr)
{
    other.m_ptr = nullptr;
}

Texture &Texture::operator=(Texture &&texture) noexcept
{
    if (&texture == this)
        return (*this);
    if (m_ptr)
        SDL_DestroyTexture(m_ptr);
    m_ptr = texture.m_ptr;
    texture.m_ptr = nullptr;
    return (*this);
}


Texture::~Texture()
{
    if (m_ptr)
        SDL_DestroyTexture(m_ptr);
}

Texture &Texture::update(const Rect *rect, const void *pixels, const int &pitch)
{
    SDL_UpdateTexture(m_ptr,
                      rect ? &rect->getSdlRect() : nullptr,
                      pixels,
                      pitch);
    return (*this);
}

SDL_Texture *Texture::getPtr() const
{
    return m_ptr;
}

SDL_Rect Texture::getSdlRect() const
{
    int w;
    int h;

    SDL_QueryTexture(m_ptr, nullptr, nullptr, &w, &h);
    return ((SDL_Rect) {0, 0, w, h});
}


const SDL_RendererFlip &Texture::getFlip() const
{
    return (m_flip);
}

Texture &Texture::setFlip(const SDL_RendererFlip &flip)
{
    m_flip = flip;
    return (*this);
}

const float &Texture::getAngle() const
{
    return (m_angle);
}

Texture &Texture::rotate(const float &angle)
{
    m_angle += angle;
    return (*this);
}

const Point &Texture::getCenter() const
{
    return (m_center);
}

Texture &Texture::setCenter(const Point &center)
{
    m_center = center;
    return (*this);
}

Texture &Texture::setBlendMode(const SDL_BlendMode &blendMode)
{
    SDL_SetTextureBlendMode(m_ptr, blendMode);
    return (*this);
}

Texture &Texture::setColorMod(const Uint8 &r, const Uint8 &g, const Uint8 &b)
{
    SDL_SetTextureColorMod(m_ptr, r, g, b);
    return (*this);
}

SDL_BlendMode Texture::getBlendMode() const
{
    SDL_BlendMode blendMode;

    SDL_GetTextureBlendMode(m_ptr, &blendMode);
    return (blendMode);
}

SDL_Color Texture::getColorMod() const
{
    SDL_Color colorMod;

    SDL_GetTextureColorMod(m_ptr, &colorMod.r, &colorMod.g, &colorMod.b);
    return (colorMod);
}

Texture &Texture::setAlphaMod(const Uint8 &alpha)
{
    SDL_SetTextureAlphaMod(m_ptr, alpha);
    return (*this);
}

Uint8 Texture::GetAlphaMod() const
{
    Uint8 alpha;

    SDL_GetTextureAlphaMod(m_ptr, &alpha);
    return (alpha);
}

//
//  Texture &Texture::operator=(const Texture &texture)
//  {
//      m_ptr = texture.getPtr();
//      return (*this);
//  }

}   //  namespace vra
