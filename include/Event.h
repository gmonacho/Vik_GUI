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

#ifndef EVENT_H_
#define EVENT_H_

#include <string>
#include <SDL_quit.h>
#include <SDL_events.h>
#include "Point.h"

namespace vra
{

class Event
{
 public:
        Event();

        virtual ~Event();

        /**
         * 	update/refresh sdl's events and the Event object
         */
        Event &update();

        /**
         * get the sdl's structure SDL_Event
         * @return SDL_Event structure
         */
        const SDL_Event &getEvent() const;

        /**
         * wait for an sdl's event
         * @return the SDL_Event structure
         */
        const SDL_Event &waitEvent();

        /**
         * ask if the key is pressed
         * @param sdl_code
         * @return true if the key is pressed or false if it is not
         */
        bool isKeyPressed(int sdl_code);

        /**
         * ask if the mouse button is pressed
         * @param sdl_button
         * @return true if the button is pressed or false if it is not
         */
        bool isMousePressed(Uint32 sdl_button);

        /**
         * This function will start accepting Unicode text input events in the focused SDL window,
         * and start emitting SDL_TEXTINPUT and SDL_TEXTEDITING events.
         * Please use this function in pair with stopTextInput().
         */
        Event &startTextInput();

        /**
         * stop text input reception
         */
        Event &stopTextInput();

        /**
         * get the last text input (text input reception must be started with startTextInput())
         * @return textInput
         */
        const std::string getLastTextInput() const;

        /**
         * aks if the text input is active
         * @return true if the text input is active or false if it is not
         */
        bool isTextInputActive();

        /**
         * @return an OR'd combination of the modifier keys for the keyboard
         */
        SDL_Keymod getModState();
        //  getKeyboardFocus?
        //  setTextInputRect();
        //  Edition de texte

         /**
         *
         * @return the mouse's position
         */

        Point getMousePosition() const;

 private:
        const Uint8 *m_keyboard;
        int m_keyboardSize;
        SDL_Event m_event;
        int m_mouseX;
        int m_mouseY;
};
}   // namespace vra

#endif  // EVENT_H_
