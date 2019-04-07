//
// Created by gal on 07/04/19.
//

#include "VRA_Window.h"
#include "VRA_Renderer.h"

VRA_Renderer::VRA_Renderer() : m_ptr(nullptr)
{
}

VRA_Renderer::VRA_Renderer(const VRA_Window& window,
                           bool         auto_choice,
                           Uint32      sdl_flags)
{
	int     index = 0;

	if (auto_choice)
		index = -1;
	if (!(m_ptr = SDL_CreateRenderer(window.get_ptr(), index, sdl_flags)))
		throw std::bad_alloc();
}

VRA_Renderer::~VRA_Renderer()
{
	if (m_ptr)
		SDL_DestroyRenderer(m_ptr);
}

