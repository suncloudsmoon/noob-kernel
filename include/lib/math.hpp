/*
 * Copyright (c) 2021, suncloudsmoon and the noob-kernel contributors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef MATH_HPP
#define MATH_HPP

namespace nlib {
	// Need to fix this: https://en.wikipedia.org/wiki/Proof_that_22/7_exceeds_%CF%80
	constexpr double PI = (double) 22 / 7;

	void srand(unsigned long seed);
	unsigned long rand(unsigned long start, unsigned long end);
	
	template<class T>
	constexpr T abs(T num) {
		return (num < 0) ? -num : num;
	}

	template<class T>
	constexpr double pow(T base, int exponent) {
		double result = 1; // PROPERTY: anything to the power of 0 is 1; thus `result` is 1 by default
		if (exponent <= 0) {
			for (int i = -1; i >= exponent; i--) {
				result *= 1 / abs<double>(base); // 2^-2 = 1/2^2
			}
		} else {
			for (int i = 1; i <= exponent; i++) {
				result *= base; // 2^2 = 1*2*2
			}
		}
		return result;
	}

	constexpr double exp(int x) {
		return pow(PI, x);
	}
}

#endif /* MATH_HPP */