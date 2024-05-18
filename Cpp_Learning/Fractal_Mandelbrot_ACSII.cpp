#include <iostream>
#include <fstream>
#include <complex>


int mandelbrotIteration(const std::complex<double>& c, int iter = 255) {
	std::complex<double> z(0, 0);
	int n = 0;
	while (std::abs(z) <= 2.0 && n < iter) {
		z = z * z + c;
		n++;
	}

	return n;
}

void printMandelbrot(std::ostream& os , int width = 80, int height = 40, double x0 = -2.0, double x1 = 1.0,
	double y0 = -1.0, double y1 = 1.0, int iter = 255) {

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			double real = x0 + (x / (double)width) * (x1 - x0);
			double imag = y0 + (y / (double)height) * (y1 - y0);

			std::complex<double> c(real, imag);
			int iterations = mandelbrotIteration(c, iter);

			char symbol;
			if (iterations == iter) {
				symbol = '#';
			}
			else {
				symbol = '.';
			}

			os << symbol;
		}
		os << '\n';
	}
}



int main() {
	printMandelbrot(std::cout , 120, 35, -2.0, 1.0, -1.0, 1.0, 1000);

	std::ofstream ofs("mandelbrot.txt");

	printMandelbrot(ofs, 600, 400, - 2.0, 1.0, -1.0, 1.0, 10000);

	ofs.close();

	std::cin.get();

	std::cout << "End of program \n";

	return 0;
}