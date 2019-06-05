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

#ifndef VIK_WRAP_FONT_H
#define VIK_WRAP_FONT_H

#include <string>
#include <SDL_ttf.h>
#include "Point.h"
#include "Texture.h"


class Renderer;


namespace vra {

	class Font {
	public:
		explicit Font();

		explicit Font(TTF_Font *font);

		explicit Font(const std::string &fontPath, const int &pixelHeight);

		TTF_Font *getPtr() const;

		int getStyle() const;

		void setStyle(int style);

		int getOutline() const;

		void setOutline(int outline);

		int getHinting() const;

		void setHinting(int hinting);

		int getKerning() const;

		void setkerning(int allowed);

		int getHeight() const;

		int getAscent() const;

		int getDescent() const;

		int getLineSkip() const;

		void GetGlyphMetrics(Uint16 ch, int &minx, int &maxx, int &miny, int &maxy, int &advance) const;

		virtual ~Font();

		Point getSizeText(const std::string &text) const;

		Point getSizeUTF8(const std::string &text) const;

		Point getSizeUNICODE(const Uint16 *text) const;

		Texture renderText(const Renderer &rend, const std::string &text, SDL_Color color);

		Texture renderTextUTF8(const Renderer &rend, const std::string &text, SDL_Color color);

		Texture renderTextUNICODE(const Renderer &rend, const Uint16 *text, SDL_Color color);

		Texture renderTextGlyph(const Renderer &rend, Uint16 ch, SDL_Color color);

		Texture renderTextShaded(const Renderer &rend, const std::string &text, SDL_Color fg, SDL_Color bg);

		Texture renderTextUTF8Shaded(const Renderer &rend, const std::string &text, SDL_Color fg, SDL_Color bg);

		Texture renderTextUNICODEShaded(const Renderer &rend, const Uint16 *text, SDL_Color fg, SDL_Color bg);

		Texture renderTextGlyphShaded(const Renderer &rend, Uint16 text, SDL_Color fg, SDL_Color bg);

		Texture renderTextBlended(const Renderer &rend, const std::string &text, SDL_Color color);

		Texture renderTextUTF8Blended(const Renderer &rend, const std::string &text, SDL_Color color);

		Texture renderTextUNICODEBlended(const Renderer &rend, const Uint16 *text, SDL_Color color);

		Texture renderTextGlyphBlended(const Renderer &rend, Uint16 ch, SDL_Color color);

	private:
		TTF_Font *m_font;
	};

}

#endif //VIK_WRAP_FONT_H
