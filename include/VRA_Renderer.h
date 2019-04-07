//
// Created by gal on 07/04/19.
//

#ifndef VIK_WRAP_VRA_RENDERER_H
#define VIK_WRAP_VRA_RENDERER_H


#include <SDL_render.h>

class VRA_Renderer
{
public:
	VRA_Renderer();

	VRA_Renderer(const VRA_Window& window,
	             bool         auto_choice,
	             Uint32      sdl_flags);
	virtual ~VRA_Renderer();

private:
	SDL_Renderer    *m_ptr;

};


#endif //VIK_WRAP_VRA_RENDERER_H
