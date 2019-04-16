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

VRA_Window::VRA_Window(const std::string &title, int x, int y, int w, int h, Uint32 sdl_flags) : m_rend(nullptr)
{
	if ((m_ptr = SDL_CreateWindow(title.c_str(), x, y, w, h, sdl_flags)) == nullptr)
			throw std::bad_alloc();
}

VRA_Window::~VRA_Window()
{
	if (m_ptr)
		SDL_DestroyWindow(m_ptr);
}

SDL_Window *VRA_Window::getPtr() const
{
	return m_ptr;
}

void VRA_Window::setRend(VRA_Renderer *rend)
{
	m_rend = rend;
}

VRA_Renderer *VRA_Window::getRend() const
{
	return (m_rend);
}

void VRA_Window::setOpacity(const float &opacity)
{
	SDL_SetWindowOpacity(m_ptr, opacity);
}

float VRA_Window::getOpacity() const
{
	float   opacity;

	SDL_GetWindowOpacity(m_ptr, &opacity);
	return (opacity);
}

void VRA_Window::setBrightness(const float &brightness)
{
	SDL_SetWindowBrightness(m_ptr, brightness);
}

float VRA_Window::getBrightness() const
{
	return (SDL_GetWindowBrightness(m_ptr));
}

void VRA_Window::setBordered(const bool &bordered)
{
	SDL_SetWindowBordered(m_ptr, static_cast<SDL_bool>(bordered));
}

void VRA_Window::setFullscreen(const Uint32 &flags)
{
	SDL_SetWindowFullscreen(m_ptr, flags);
}

void VRA_Window::setSize(int width, int height)
{
	if (width > 0 && height > 0)
		SDL_SetWindowSize(m_ptr, width, height);
}

void VRA_Window::getSize(int *width, int *height) const
{
	SDL_GetWindowSize(m_ptr, width, height);
}

void VRA_Window::setResizable(const bool &resizable)
{
	SDL_SetWindowResizable(m_ptr, static_cast<SDL_bool>(resizable));
}

void VRA_Window::show()
{
	SDL_ShowWindow(m_ptr);
}

void VRA_Window::hide()
{
	SDL_HideWindow(m_ptr);
}

void VRA_Window::raise()
{
	SDL_RaiseWindow(m_ptr);
}

VRA_Window::VRA_Window(VRA_Window &&win) noexcept : m_ptr(win.m_ptr), m_rend(win.m_rend)
{
	win.m_ptr = nullptr;
	win.m_rend = nullptr;
}

VRA_Window& VRA_Window::operator=(VRA_Window &&win) noexcept
{
	if (m_ptr)
		SDL_DestroyWindow(m_ptr);
	m_ptr = win.m_ptr;
	win.m_ptr = nullptr;
	return (*this);
}


