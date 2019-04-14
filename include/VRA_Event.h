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

#ifndef VIK_WRAP_VRA_EVENT_H
#define VIK_WRAP_VRA_EVENT_H


#include <SDL_quit.h>
#include <SDL_events.h>
#include <string>

class VRA_Event
{
public:
	explicit            VRA_Event();
	virtual             ~VRA_Event();
	void                update();
	const SDL_Event    &getEvent() const;
	const SDL_Event    &waitEvent();
	bool                isKeyPressed(int sdl_code);
	bool                isMousePressed(Uint32 sdl_button);
	void                startTextInput();
	void                stopTextInput();
	const std::string   getLastTextInput() const;
	bool                isTextInputActive();
	SDL_Keymod          getModState();
	//  getKeyboardFocus?
	//  setTextInputRect();
	//  Edition de texte
	int                 getMouseX() const;
	int getMouseY() const;

private:
	const Uint8        *m_keyboard;
	int                 m_keyboardSize;
	SDL_Event           m_event;
	int                 m_mouseX;
	int                 m_mouseY;

};


#endif //VIK_WRAP_VRA_EVENT_H
