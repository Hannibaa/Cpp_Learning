#include <iostream>
#include <complex>

template<typename Function>
void make_mandelbrot(Function func);

void make_julia();

// we going to add some limit to this 
// also we need to using CConsole for this;
void make_mandelbrot(int lx = 145, int ly = 35) {
	std::complex<float>  corner_dn{ -2.f, -1.12f };
	std::complex<float>  corner_up{ 0.7f, 1.12f };

	for (float i = corner_dn.imag(); i < corner_up.imag(); i += 0.06f)
	{
		for (float r = corner_dn.real(); r < corner_up.real(); r += 0.025)
		{
			std::complex<float> c{ r,i };
			size_t iter = 0;
			// math function
			for (std::complex<float> z = c; iter < 26 && abs(z) < 2; ++iter)
				z = z * z + c;

			// print the mandelbrot set value;
			std::cout << static_cast<char>(iter + 32);
		}

		std::cout << '\n';
	}
}


int main() {

	make_mandelbrot();

	return 0;
}