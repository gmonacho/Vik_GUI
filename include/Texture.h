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

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <string>
#include <SDL_ttf.h>
#include "Rect.h"
#include "Point.h"



namespace vra
{

class Renderer;

class Texture
{
 public:
    Texture();

    explicit Texture(SDL_Texture *sdlTexture);

    explicit Texture(const Renderer &rend, const std::string &file);

    explicit Texture(const Renderer &rend,
                     Uint32 format,
                     int access,
                     int w,
                     int h);

    virtual                     ~Texture();

    Texture(Texture&& other) noexcept;

    Texture &operator=(Texture &&texture) noexcept;

    //  Texture(const Texture& other) = delete;
    //  Texture(const Texture& other) = delete;
    //  Texture &operator=(const Texture &texture) = delete;

    Texture &update(const Rect *rect, const void *pixels, const int &pitch);

    SDL_Texture *getPtr() const;

    SDL_Rect getSdlRect() const;

    const SDL_RendererFlip &getFlip() const;

    void setFlip(const SDL_RendererFlip &flip);

    const double &getAngle() const;

    void rotate(const double &angle);

    const Point &getCenter() const;

    void setCenter(const Point &center);

    void setBlendMode(const SDL_BlendMode &blendMode);

    SDL_BlendMode getBlendMode() const;

    void setColorMod(const Uint8 &r, const Uint8 &g, const Uint8 &b);

    SDL_Color getColorMod() const;

    void setAlphaMod(const Uint8 &alpha);

    Uint8 GetAlphaMod() const;

 protected:
    SDL_Texture *m_ptr;
    SDL_RendererFlip m_flip;
    Point m_center;
    double m_angle;
};
}   //  namespace vra

#endif  //   TEXTURE_H_
