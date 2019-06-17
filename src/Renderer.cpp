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
#include "Exception.h"
#include "Window.h"
#include "Renderer.h"
#include "Texture.h"
#include "Circle.h"
#include "Polygon.h"

namespace vra
{

Renderer::Renderer(const Window &window,
                    bool autoChoice,
                    Uint32 sdl_flags)
{
    int index = (autoChoice) ? -1 : 0;

    if ((m_ptr = SDL_CreateRenderer(window.getPtr(),
                                    index,
                                    sdl_flags)) == nullptr)
        throw(Exception("SDL_CreateRenderer"));
}

Renderer::Renderer(Renderer &&rend) noexcept : m_ptr(rend.m_ptr)
{
    rend.m_ptr = nullptr;
}

Renderer &Renderer::operator=(Renderer &&rend) noexcept
{
    if (m_ptr)
        SDL_DestroyRenderer(m_ptr);
    m_ptr = rend.m_ptr;
    rend.m_ptr = nullptr;
    return (*this);
}

Renderer::~Renderer()
{
    if (m_ptr)
        SDL_DestroyRenderer(m_ptr);
}

SDL_Renderer *Renderer::getPtr() const
{
    return m_ptr;
}

SDL_RendererInfo Renderer::getInfo() const
{
    SDL_RendererInfo renderInfo;

    SDL_GetRendererInfo(m_ptr, &renderInfo);
    return (renderInfo);
}

SDL_Rect Renderer::getSdlRect() const
{
    int w;
    int h;

    SDL_GetRendererOutputSize(m_ptr, &w, &h);
    return ((SDL_Rect) {0, 0, w, h});
}

Renderer &Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(m_ptr, r, g, b, a);
    return (*this);
}

SDL_Color Renderer::getDrawColor()
{
    SDL_Color drawColor;

    SDL_GetRenderDrawColor(m_ptr,
                            &drawColor.r,
                            &drawColor.g,
                            &drawColor.b,
                            &drawColor.a);
    return (drawColor);
}

Renderer &Renderer::setTarget(Texture *texture)
{
    SDL_SetRenderTarget(m_ptr, texture ? texture->getPtr() : nullptr);
    return (*this);
}

Renderer &Renderer::setDrawBlendMode(SDL_BlendMode sdlBlendMode)
{
    SDL_SetRenderDrawBlendMode(m_ptr, sdlBlendMode);
    return (*this);
}

SDL_BlendMode Renderer::getDrawBlendMode()
{
    SDL_BlendMode sdlBlendMode;

    SDL_GetRenderDrawBlendMode(m_ptr, &sdlBlendMode);
    return (sdlBlendMode);
}

Renderer &Renderer::setViewport(const Rect &rect)
{
    SDL_RenderSetViewport(m_ptr, &rect.getSdlRect());
    return (*this);
}

Rect Renderer::getViewport() const
{
    Rect rect{};
    SDL_Rect sdlRect;

    SDL_RenderGetViewport(m_ptr, &sdlRect);
    rect.setSdlRect(sdlRect);
    return (rect);
}

Renderer &Renderer::clear()
{
    SDL_RenderClear(m_ptr);
    return (*this);
}

Renderer &Renderer::draw()
{
    SDL_RenderPresent(m_ptr);
    return (*this);
}

Renderer &Renderer::drawPoint(const Point &point)
{
    SDL_RenderDrawPoint(m_ptr, point.getX(), point.getY());
    return (*this);
}

Renderer &Renderer::drawLine(const Line &line)
{
    SDL_RenderDrawLine(m_ptr,
                        line.getX1(),
                        line.getY1(),
                        line.getX2(),
                        line.getY2());
    return (*this);
}

Renderer &Renderer::drawRect(const Rect &rect)
{
    SDL_RenderDrawRect(m_ptr, &rect.getSdlRect());
    return (*this);
}

Renderer &Renderer::fillRect(const Rect &rect)
{
    SDL_RenderFillRect(m_ptr, &rect.getSdlRect());
    return (*this);
}

Renderer &Renderer::drawTexture(const Texture &texture,
                            const Rect *srcRect,
                            const Rect *dstRect)
{
    int     ret{0};

    if (texture.getFlip() == SDL_FLIP_NONE && texture.getAngle() == 0)
    {
        ret = SDL_RenderCopy(m_ptr, texture.getPtr(),
                        srcRect ? &srcRect->getSdlRect() : nullptr,
                        dstRect ? &dstRect->getSdlRect() : nullptr);
    }
    else
    {
        ret = SDL_RenderCopyEx(m_ptr,
                            texture.getPtr(),
                            srcRect ? &srcRect->getSdlRect() : nullptr,
                            dstRect ? &dstRect->getSdlRect() : nullptr,
                            texture.getAngle(),
                            &texture.getCenter().getSdlPoint(),
                            texture.getFlip());
    }
    if (ret < 0)
        throw(Exception{"drawTexture"});
    return (*this);
}

Renderer &Renderer::drawCircle(const Circle &circle)
{
    int     x{0},
            y{circle.getRadius()},
            m{5 - 4 - circle.getRadius()};
    while (x <= y)
    {
        drawPoint(Point{x + circle.getPosition().getX(),
                        y + circle.getPosition().getY()});
        drawPoint(Point{y + circle.getPosition().getX(),
                        x + circle.getPosition().getY()});
        drawPoint(Point{-x + circle.getPosition().getX(),
                        y + circle.getPosition().getY()});
        drawPoint(Point{-y + circle.getPosition().getX(),
                        x + circle.getPosition().getY()});
        drawPoint(Point{x + circle.getPosition().getX(),
                        -y + circle.getPosition().getY()});
        drawPoint(Point{y + circle.getPosition().getX(),
                        -x + circle.getPosition().getY()});
        drawPoint(Point{-x + circle.getPosition().getX(),
                        -y + circle.getPosition().getY()});
        drawPoint(Point{-y + circle.getPosition().getX(),
                        -x + circle.getPosition().getY()});
        if (m > 0)
        {
            y--;
            m -= 8 * y;
        }
        x++;
        m += 8 * x + 4;
    }
    return (*this);
}


Renderer &Renderer::drawPolygon(const Polygon &polygon)
{
    std::vector<Point>  tabPoint{polygon.getTabPoint()};
    Point               previousPoint{tabPoint[0]};

    drawLine(Line{tabPoint[tabPoint.size() - 1], previousPoint});
    for (int i{1}; i < tabPoint.size(); i++)
    {
        drawLine(Line{previousPoint, tabPoint[i]});
        previousPoint = tabPoint[i];
    }
    return (*this);
}

}   //  namespace vra
