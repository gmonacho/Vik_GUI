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

#ifndef VIK_WRAP_VRA_THREAD_H
#define VIK_WRAP_VRA_THREAD_H


#include <string>
#include <SDL_thread.h>

class VRA_Thread
{
public:
	explicit        VRA_Thread(SDL_ThreadFunction function, const std::string &name, void *data);
	virtual         ~VRA_Thread();

	void            detach();
	void            wait(int &status);
	std::string     getName() const;
	SDL_threadID    getID() const;
	void setPriority(SDL_ThreadPriority priority);

private:
	SDL_Thread  *m_ptr;
};

SDL_threadID VRA_ThreadID();


#endif //VIK_WRAP_VRA_THREAD_H
