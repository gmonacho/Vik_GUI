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
#include <SDL2/SDL_ttf.h>
#include "Point.h"
#include "Texture.h"


class Renderer;


namespace vra {

	class Font {
	public:
		/**
		 * default constructor, initialize with a nullptr
		 */
		explicit Font();

		/**
		 * Construct from an existing TTF_Font
		 * @param TTF_Font font
		 */
		explicit Font(TTF_Font *font);

		/**
		 * Construct from a .ttf or .fon file
		 * @param fontPath font file's path
		 * @param pixelHeight Point size (based on 72DPI) to load font as.
		 * This basically translates to pixel height.
		 */
		explicit Font(const std::string &fontPath, const int &pixelHeight);

		/**
		 * Destroy the font properly
		 */
		virtual ~Font();

		/**
		 * get the sdl structure TTF_Font
		 * @return a pointeur to the TTF_Font structure
		 */
		TTF_Font *getPtr() const;

		/**
		 * get the font style using a sdl bitmask
		 * @return The style as a bitmask composed of the following masks:
		 * TTF_STYLE_BOLD
		 * TTF_STYLE_ITALIC
		 * TTF_STYLE_UNDERLINE
		 * TTF_STYLE_STRIKETHROUGH
		 * If no style is set then TTF_STYLE_NORMAL is returned.
		 */
		int getStyle() const;

		/**
		 * set the font style using a sdl bitmask :
		 * TTF_STYLE_NORMAL
		 * TTF_STYLE_BOLD
		 * TTF_STYLE_ITALIC
		 * TTF_STYLE_UNDERLINE
		 * TTF_STYLE_STRIKETHROUGH
		 */
		void setStyle(int style);

		/**
 		 * Get the current outline size of the loaded font.
 		 * @return The loaded font outline.
 		 */
		int getOutline() const;

		/**
		 * set the current outline size of the font.
		 * @param outline The loaded font to get the outline size of.
		 */
		void setOutline(int outline);

		/**
		 * Get the current hinting setting of the font.
		 * @return The hinting type matching one of the following defined values:
		 * TTF_HINTING_NORMAL
		 * TTF_HINTING_LIGHT
		 * TTF_HINTING_MONO
		 * TTF_HINTING_NONE
		 * If no hinting is set then TTF_HINTING_NORMAL is returned.
		 */
		int getHinting() const;

		/**
		 * Set the current hinting setting of the font using sdl bitmask.
		 * TTF_HINTING_NORMAL
		 * TTF_HINTING_NORMAL
		 * TTF_HINTING_LIGHT
		 * TTF_HINTING_MONO
		 * TTF_HINTING_NONE
 		 */
		void setHinting(int hinting);

		/**
		 * Get the current kerning setting of the font.
		 * @return  0(zero) if kerning is disabled. A non-zero value is returned when enabled.
		 * The default for a newly loaded font is enabled(1).
		 */
		int getKerning() const;

		/**
		 * Set the current kerning setting of the font.
		 * @param allowed
		 * 0 to diable kerning.
		 * non-zero to enable kerning. The default is 1, enabled.
		 */
		void setkerning(int allowed);

		/**
		 * Get the maximum pixel height of all glyphs of the loaded font.
		 * You may use this height for rendering text as close together vertically as possible,
		 * though adding at least one pixel height to it will space it so they can't touch.
		 * Remember that SDL_ttf doesn't handle multiline printing,
		 * so you are responsible for line spacing,
		 * see the fontObj.getLineSkip as well.
		 * @return The maximum pixel height of all glyphs in the font.
		 */
		int getHeight() const;

		/**
		 * Get the maximum pixel ascent of all glyphs of the loaded font.
		 * This can also be interpreted as the distance from the top of the font to the baseline.
		 * It could be used when drawing an individual glyph relative to a top point,
		 * by combining it with the glyph's maxy metric to resolve the top of the rectangle
		 * used when blitting the glyph on the screen.
		 *
		 * rect.y = top + TTF_FontAscent(font) - glyph_metric.maxy;
		 * @return The maximum pixel ascent of all glyphs in the font.
		 */
		int getAscent() const;

		/**
		 * Get the maximum pixel descent of all glyphs of the loaded font.
		 * This can also be interpreted as the distance from the baseline to the bottom of the font.
		 * It could be used when drawing an individual glyph relative to a bottom point,
		 * by combining it with the glyph's maxy metric to resolve the top of the rectangle
		 * used when blitting the glyph on the screen.
		 * rect.y = bottom - TTF_FontDescent(font) - glyph_metric.maxy;
		 * @return The maximum pixel height of all glyphs in the font.
		 */
		int getDescent() const;

		/**
		 * Get the recommended pixel height of a rendered line of text of the loaded font.
		 * This is usually larger than the TTF_FontHeight of the font.
		 * @return The maximum pixel height of all glyphs in the font.
		 */
		int getLineSkip() const;

		/**
		 * Get desired glyph metrics of the UNICODE chargiven in ch from the font.
		 * @param ch the UNICODE char to get the glyph metrics for.
		 * @param minx pointer to int to store the returned minimum X offset into,
		 * or NULL when no return value desired.
		 * @param maxx pointer to int to store the returned maximum X offset into,
		 * or NULL when no return value desired.
		 * @param miny pointer to int to store the returned minimum Y offset into,
		 * or NULL when no return value desired.
		 * @param maxy pointer to int to store the returned maximum Y offset into,
		 * or NULL when no return value desired.
		 * @param advance pointer to int to store the returned advance offset into,
		 * or NULL when no return value desired.
		 */
		void GetGlyphMetrics(Uint16 ch, int &minx, int &maxx, int &miny, int &maxy, int &advance) const;

		/**
		 * Calculate the resulting surface size of the LATIN1 encoded text rendered using font.
		 * No actual rendering is done,
		 * however correct kerning is done to get the actual width.
		 * The height returned in h is the same as you can get using 3.3.10 TTF_FontHeight.
		 * @param text The LATIN1 null terminated string to size up.
		 * @return A Point object containing the size .x ->width .y ->height of the encoded text
		 */
		Point getSizeText(const std::string &text) const;

		/**
		 * Calculate the resulting surface size of the UTF8 encoded text rendered using font.
		 * No actual rendering is done,
		 * however correct kerning is done to get the actual width.
		 * The height returned in h is the same as you can get using 3.3.10 TTF_FontHeight.
		 * @param text The UTF8 null terminated string to size up.
		 * @return A Point object containing the size .x ->width .y ->height of the encoded text
		 */
		Point getSizeUTF8(const std::string &text) const;

		/**
		 * Calculate the resulting surface size of the UNICODE encoded text rendered using font.
		 * No actual rendering is done,
		 * however correct kerning is done to get the actual width.
		 * The height returned in h is the same as you can get using 3.3.10 TTF_FontHeight.
		 * @param text The UNICODE null terminated string to size up.
		 * @return
		 */
		Point getSizeUNICODE(const Uint16 *text) const;

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderText(const Renderer &rend, const std::string &text, SDL_Color color);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextUTF8(const Renderer &rend, const std::string &text, SDL_Color color);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextUNICODE(const Renderer &rend, const Uint16 *text, SDL_Color color);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextGlyph(const Renderer &rend, Uint16 ch, SDL_Color color);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextShaded(const Renderer &rend, const std::string &text, SDL_Color fg, SDL_Color bg);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextUTF8Shaded(const Renderer &rend, const std::string &text, SDL_Color fg, SDL_Color bg);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextUNICODEShaded(const Renderer &rend, const Uint16 *text, SDL_Color fg, SDL_Color bg);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextGlyphShaded(const Renderer &rend, Uint16 text, SDL_Color fg, SDL_Color bg);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextBlended(const Renderer &rend, const std::string &text, SDL_Color color);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextUTF8Blended(const Renderer &rend, const std::string &text, SDL_Color color);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextUNICODEBlended(const Renderer &rend, const Uint16 *text, SDL_Color color);

		/**
		 * Render the encoded text onto a new Texture
		 * @param rend
		 * @param text
		 * @param color
		 * @return Texture containing the rendered text
		 */
		Texture renderTextGlyphBlended(const Renderer &rend, Uint16 ch, SDL_Color color);

	private:
		TTF_Font *m_font;
	};

}

#endif //VIK_WRAP_FONT_H
