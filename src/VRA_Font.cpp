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
#include <VRA_Exception.h>
#include "VRA_Font.h"
#include "VRA_Renderer.h"

VRA_Font::VRA_Font() : m_font(nullptr){}

VRA_Font::VRA_Font(TTF_Font *font) : m_font(font){}

VRA_Font::VRA_Font(const std::string &fontPath, const int &pixelHeight)
{
	if (!fontPath.empty())
	{
		if (!(m_font = TTF_OpenFont(fontPath.c_str(), pixelHeight)))
		{
			std::cout << SDL_GetError() << std::endl;
			throw (VRA_Exception("TTF_OpenFont"));
		}
	}
	else
		m_font = nullptr;
}

VRA_Font::~VRA_Font()
{
	if (m_font)
		TTF_CloseFont(m_font);
}


TTF_Font *VRA_Font::getPtr() const
{
	return (m_font);
}


int VRA_Font::getStyle() const
{
	if (m_font)
		return (TTF_GetFontStyle(m_font));
	else
		return (0x00);
}

void VRA_Font::setStyle(int style)
{
	if (m_font)
		TTF_SetFontStyle(m_font, style);
}

int VRA_Font::getOutline() const
{
	if (m_font)
		return (TTF_GetFontOutline(m_font));
	else
		return (0);
}

void VRA_Font::setOutline(int outline)
{
	if (m_font)
		TTF_SetFontOutline(m_font, outline);
}

int VRA_Font::getHinting() const
{
	if (m_font)
		return (TTF_GetFontHinting(m_font));
	else
		return (0);
}

void VRA_Font::setHinting(int hinting)
{
	if (m_font)
		TTF_SetFontHinting(m_font, hinting);
}

int VRA_Font::getKerning() const
{
	if (m_font)
		return (TTF_GetFontKerning(m_font));
	else
		return (0);
}

void VRA_Font::setkerning(int allowed)
{
	if (m_font)
		TTF_SetFontKerning(m_font, allowed);
}

int VRA_Font::getHeight() const
{
	if (m_font)
		return (TTF_FontHeight(m_font));
	else
		return (0);
}

int VRA_Font::getAscent() const
{
	if (m_font)
		return (TTF_FontAscent(m_font));
	else
		return (0);
}

int VRA_Font::getDescent() const
{
	if (m_font)
		return (TTF_FontDescent(m_font));
	else
		return (0);
}

int VRA_Font::getLineSkip() const
{
	if (m_font)
		return (TTF_FontLineSkip(m_font));
	else
		return (0   );
}

void VRA_Font::GetGlyphMetrics(Uint16 ch, int &minx, int &maxx, int &miny, int &maxy, int &advance) const
{
	if (m_font)
		TTF_GlyphMetrics(m_font, ch, &minx, &maxx, &miny, &maxy, &advance);
}

VRA_Point VRA_Font::getSizeText(const std::string &text) const
{
	VRA_Point   size;
	int         w{0};
	int         h{0};

	if (m_font && !text.empty())
		TTF_SizeText(m_font, text.c_str(), &w, &h);
	size.setX(w);
	size.setY(h);
	return (size);
}

VRA_Point VRA_Font::getSizeUTF8(const std::string &text) const
{
	VRA_Point   size;
	int         w{0};
	int         h{0};

	if (m_font && !text.empty())
		TTF_SizeUTF8(m_font, text.c_str(), &w, &h);
	size.setX(w);
	size.setY(h);
	return (size);
}

VRA_Point VRA_Font::getSizeUNICODE(const Uint16 *text) const
{
	VRA_Point   size;
	int         w{0};
	int         h{0};

	if (m_font && text)
		TTF_SizeUNICODE(m_font, text, &w, &h);
	size.setX(w);
	size.setY(h);
	return (size);
}

VRA_Texture VRA_Font::renderText(const VRA_Renderer &rend, const std::string &text, SDL_Color color)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font)
	{
		if (!(tmp = TTF_RenderText_Solid(m_font, text.c_str(), color)))
			throw (VRA_Exception("TTF_RenderText_Solid"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture{sdlTexture});
}

VRA_Texture VRA_Font::renderTextUTF8(const VRA_Renderer &rend, const std::string &text, SDL_Color color)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font)
	{
		if (!(tmp = TTF_RenderUTF8_Solid(m_font, text.c_str(), color)))
			throw (VRA_Exception("TTF_RenderUTF8_Solid"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextUNICODE(const VRA_Renderer &rend, const Uint16 *text, SDL_Color color)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font && text)
	{
		if (!(tmp = TTF_RenderUNICODE_Solid(m_font, text, color)))
			throw (VRA_Exception("TTF_RenderUNICODE_Solid"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextGlyph(const VRA_Renderer &rend, Uint16 ch, SDL_Color color)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font && ch)
	{
		if (!(tmp = TTF_RenderGlyph_Solid(m_font, ch, color)))
			throw (VRA_Exception("TTF_RenderGlyph_Solid"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextShaded(const VRA_Renderer &rend, const std::string &text, SDL_Color fg, SDL_Color bg)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font)
	{
		if (!(tmp = TTF_RenderText_Shaded(m_font, text.c_str(), fg, bg)))
			throw (VRA_Exception("TTF_RenderText_Shaded"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextUTF8Shaded(const VRA_Renderer &rend, const std::string &text, SDL_Color fg, SDL_Color bg)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font)
	{
		if (!(tmp = TTF_RenderUTF8_Shaded(m_font, text.c_str(), fg, bg)))
			throw (VRA_Exception("TTF_RenderUTF8_Shaded"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextUNICODEShaded(const VRA_Renderer &rend, const Uint16 *text, SDL_Color fg, SDL_Color bg)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};
	if (m_font && text)
	{
		if (!(tmp = TTF_RenderUNICODE_Shaded(m_font, text, fg , bg)))
			throw (VRA_Exception("TTF_RenderUNICODE_Shaded"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextGlyphShaded(const VRA_Renderer &rend, Uint16 ch, SDL_Color fd, SDL_Color bg)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font && ch)
	{
		if (!(tmp = TTF_RenderGlyph_Shaded(m_font, ch, fd, bg)))
			throw (VRA_Exception("TTF_RenderGlyph_Shaded"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextBlended(const VRA_Renderer &rend, const std::string &text, SDL_Color color)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font)
	{
		if (!(tmp = TTF_RenderText_Blended(m_font, text.c_str(), color)))
			throw (VRA_Exception("TTF_RenderText_Blended"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextUTF8Blended(const VRA_Renderer &rend, const std::string &text, SDL_Color color)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font)
	{
		if (!(tmp = TTF_RenderUTF8_Blended(m_font, text.c_str(), color)))
			throw (VRA_Exception("TTF_RenderUTF8_Blended"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextUNICODEBlended(const VRA_Renderer &rend, const Uint16 *text, SDL_Color color)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font && text)
	{
		if (!(tmp = TTF_RenderUNICODE_Blended(m_font, text, color)))
			throw (VRA_Exception("TTF_RenderUNICODE_Blended"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}

VRA_Texture VRA_Font::renderTextGlyphBlended(const VRA_Renderer &rend, Uint16 ch, SDL_Color color)
{
	SDL_Surface     *tmp;
	SDL_Texture     *sdlTexture{nullptr};

	if (m_font && ch)
	{
		if (!(tmp = TTF_RenderGlyph_Blended(m_font, ch, color)))
			throw (VRA_Exception("TTF_RenderGlyph_Blended"));
		if (!(sdlTexture = SDL_CreateTextureFromSurface(rend.getPtr(), tmp)))
			throw (VRA_Exception("SDL_CreateTextureFromSurface"));
		SDL_FreeSurface(tmp);
	}
	return (VRA_Texture(sdlTexture));
}









