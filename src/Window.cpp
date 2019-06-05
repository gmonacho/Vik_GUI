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

#include <Exception.h>
#include "Window.h"


namespace vra {

	Window::Window(const std::string &title, int x, int y, int w, int h, Uint32 sdl_flags) : m_rend(nullptr) {
		if ((m_ptr = SDL_CreateWindow(title.c_str(), x, y, w, h, sdl_flags)) == nullptr)
			throw (Exception("SDL_CreateWindow"));
	}

	Window::~Window() {
		if (m_ptr)
			SDL_DestroyWindow(m_ptr);
	}

	SDL_Window *Window::getPtr() const {
		return m_ptr;
	}

	void Window::setRend(Renderer *rend) {
		m_rend = rend;
	}

	Renderer *Window::getRend() const {
		return (m_rend);
	}

	void Window::setOpacity(const float &opacity) {
		SDL_SetWindowOpacity(m_ptr, opacity);
	}

	float Window::getOpacity() const {
		float opacity;

		SDL_GetWindowOpacity(m_ptr, &opacity);
		return (opacity);
	}

	void Window::setBrightness(const float &brightness) {
		SDL_SetWindowBrightness(m_ptr, brightness);
	}

	float Window::getBrightness() const {
		return (SDL_GetWindowBrightness(m_ptr));
	}

	void Window::setBordered(const bool &bordered) {
		SDL_SetWindowBordered(m_ptr, static_cast<SDL_bool>(bordered));
	}

	void Window::setFullscreen(const Uint32 &flags) {
		SDL_SetWindowFullscreen(m_ptr, flags);
	}

	void Window::setSize(int width, int height) {
		if (width > 0 && height > 0)
			SDL_SetWindowSize(m_ptr, width, height);
	}

	void Window::getSize(int *width, int *height) const {
		SDL_GetWindowSize(m_ptr, width, height);
	}

	void Window::setResizable(const bool &resizable) {
		SDL_SetWindowResizable(m_ptr, static_cast<SDL_bool>(resizable));
	}

	void Window::show() {
		SDL_ShowWindow(m_ptr);
	}

	void Window::hide() {
		SDL_HideWindow(m_ptr);
	}

	void Window::raise() {
		SDL_RaiseWindow(m_ptr);
	}

	Window::Window(Window &&win) noexcept : m_ptr(win.m_ptr), m_rend(win.m_rend) {
		win.m_ptr = nullptr;
		win.m_rend = nullptr;
	}

	Window &Window::operator=(Window &&win) noexcept {
		if (m_ptr)
			SDL_DestroyWindow(m_ptr);
		m_ptr = win.m_ptr;
		win.m_ptr = nullptr;
		return (*this);
	}

}
