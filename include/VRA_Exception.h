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

#ifndef VIK_WRAP_VRA_EXCEPTION_H
#define VIK_WRAP_VRA_EXCEPTION_H

#include <string>
#include <stdexcept>

class VRA_Exception : public std::runtime_error
{
private:
	std::string m_function;
	std::string m_error;

public:

	/**
	 *
	 * @param function which cause the error
	 */
	explicit VRA_Exception(const std::string &function);

	/**
	 *
	 * @return the function which cause the error
	 */
	const std::string &getFunction() const;

	/**
	 *
	 * @return the sdl's error
	 */
	const std::string &getError() const;

	~VRA_Exception() noexcept override;
};


#endif //VIK_WRAP_VRA_EXCEPTION_H
