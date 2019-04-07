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

#include "VRA_Window.h"
#include "VRA_Renderer.h"

VRA_Renderer::VRA_Renderer() : m_ptr(nullptr) {}

VRA_Renderer::VRA_Renderer(const VRA_Window& window,
                           bool         auto_choice,
                           Uint32      sdl_flags)
{
	int     index = 0;

	if (auto_choice)
		index = -1;
	if ((m_ptr = SDL_CreateRenderer(window.getPtr(), index, sdl_flags)) == nullptr)
		throw std::bad_alloc();
}

VRA_Renderer::~VRA_Renderer()
{
	if (m_ptr)
		SDL_DestroyRenderer(m_ptr);
}

void VRA_Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(m_ptr, r, g, b, a);
}

void VRA_Renderer::clear()
{
	SDL_RenderClear(m_ptr);
}

void VRA_Renderer::display()
{
	SDL_RenderPresent(m_ptr);
}

