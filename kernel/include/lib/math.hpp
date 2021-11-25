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