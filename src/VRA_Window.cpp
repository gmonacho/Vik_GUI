//
// Created by gal on 07/04/19.
//

#include "VRA_Window.h"

VRA_Window::VRA_Window(const std::string &title, int x, int y, int w, int h, Uint32 sdl_flags)
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

void VRA_Window::setOpacity(float opacity)
{
	SDL_SetWindowOpacity(m_ptr, opacity);
}

float VRA_Window::getOpacity()
{
	float   opacity;

	SDL_GetWindowOpacity(m_ptr, &opacity);
	return (opacity);
}

void VRA_Window::setBrightness(float brightness)
{
	SDL_SetWindowBrightness(m_ptr, brightness);
}

float VRA_Window::getBrightness()
{
	return (SDL_GetWindowBrightness(m_ptr));
}

void VRA_Window::setBordered(bool bordered)
{
	SDL_SetWindowBordered(m_ptr, static_cast<SDL_bool>(bordered));
}
