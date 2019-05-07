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

#include <SDL_keyboard.h>
#include <new>
#include <SDL_events.h>
#include <VRA_Exception.h>
#include "VRA_Event.h"

VRA_Event::VRA_Event()
{
	m_keyboardSize = 0;
	if ((m_keyboard = SDL_GetKeyboardState(&m_keyboardSize)) == nullptr)
		throw (VRA_Exception("SDL_GetKeyboardState"));
	SDL_GetMouseState(&m_mouseY, &m_mouseX);
}

VRA_Event::~VRA_Event() = default;

void VRA_Event::update()
{
	SDL_PumpEvents();
	SDL_PollEvent(&m_event);
	SDL_GetMouseState(&m_mouseY, &m_mouseX);
}

const SDL_Event &VRA_Event::getEvent() const
{
	return (m_event);
}

const SDL_Event &VRA_Event::waitEvent()
{
	SDL_WaitEvent(&m_event);
	return (m_event);
}

bool VRA_Event::isKeyPressed(int sdl_code)
{
	if (sdl_code >= m_keyboardSize)
		return (false);
	return (m_keyboard[sdl_code] != 0);
}

void VRA_Event::startTextInput()
{
	SDL_StartTextInput();
}

void VRA_Event::stopTextInput()
{
	SDL_StopTextInput();
}

const std::string VRA_Event::getLastTextInput() const
{
	std::string lastTextInput{};
	if (m_event.type == SDL_TEXTINPUT)
		lastTextInput = m_event.text.text;
	return (lastTextInput);
}

bool VRA_Event::isTextInputActive()
{
	return (SDL_IsTextInputActive());
}

SDL_Keymod VRA_Event::getModState()
{
	return (SDL_GetModState());
}

bool VRA_Event::isMousePressed(Uint32 sdl_button)
{
	return (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(sdl_button));
}

int VRA_Event::getMouseX() const
{
	return m_mouseX;
}

int VRA_Event::getMouseY() const
{
	return m_mouseY;
}

