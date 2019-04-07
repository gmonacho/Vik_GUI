//
// Created by gal on 07/04/19.
//

#ifndef VIK_WRAP_VRA_WINDOW_H
#define VIK_WRAP_VRA_WINDOW_H

#include <SDL_video.h>
#include <string>

class VRA_Window
{

public:

	VRA_Window(const std::string &title, int x, int y, int w, int h, Uint32 sdl_flags);
	virtual ~VRA_Window();
	SDL_Window *getPtr() const;
	void    setOpacity(float opacity);
	float   getOpacity();
	void    setBrightness(float brightness);
	float   getBrightness();
	void    setBordered(bool bordered);

private:

	SDL_Window  *m_ptr;

};


#endif //VIK_WRAP_VRA_WINDOW_H
