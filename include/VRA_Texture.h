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

#ifndef VIK_WRAP_VRA_TEXTURE_H
#define VIK_WRAP_VRA_TEXTURE_H

#include <optional>
#include <SDL_ttf.h>
#include "VRA_Rect.h"
#include "VRA_Point.h"

class VRA_Renderer;

class VRA_Texture
{
public:
	explicit                    VRA_Texture();
	explicit                    VRA_Texture(SDL_Texture *sdlTexture);
	explicit                    VRA_Texture(const VRA_Renderer &rend, const std::string &file);
	explicit                    VRA_Texture(const VRA_Renderer &rend, Uint32 format, int access, int w, int h);

	virtual                     ~VRA_Texture();


	VRA_Texture                 &update(const std::optional<VRA_Rect> &rect, const void *pixels, const int &pitch);

	SDL_Texture                 *getPtr() const;
	SDL_Rect                    getSdlRect() const;

	const SDL_RendererFlip      &getFlip() const;
	void                        setFlip(const SDL_RendererFlip &flip);

	const double                &getAngle() const;
	void                        rotate(const double &angle);

	const VRA_Point             &getCenter() const;
	void                        setCenter(const VRA_Point &center);

	void                        setBlendMode(const SDL_BlendMode &blendMode);
	SDL_BlendMode               getBlendMode() const;

	void                        setColorMod(const Uint8 &r, const Uint8 &g, const Uint8 &b);
	SDL_Color                   getColorMod() const;

	void                        setAlphaMod(const Uint8 &alpha);
	Uint8                       GetAlphaMod() const;


protected:
	SDL_Texture         *m_ptr;
	SDL_RendererFlip    m_flip;
	VRA_Point           m_center;
	double              m_angle;

};



#endif //VIK_WRAP_VRA_TEXTURE_H
