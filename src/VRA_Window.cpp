//
// Created by gal on 07/04/19.
//

#include "VRA_Window.h"



VRA_Window::VRA_Window() : m_ptr(nullptr) {}

VRA_Window::VRA_Window(const std::string &title, int x, int y, int w, int h, Uint32 sdl_flags)
{
	if (!(m_ptr = SDL_CreateWindow(title.c_str(), x, y, w, h, sdl_flags)))
			throw std::bad_alloc();
}

VRA_Window::~VRA_Window()
{
	if (m_ptr)
		SDL_DestroyWindow(m_ptr);
}

SDL_Window *VRA_Window::get_ptr() const
{
	return m_ptr;
}
