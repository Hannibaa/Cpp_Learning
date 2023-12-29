#include <iostream>
#include <fstream>
#include <MyLib/math/matrix_utility.hpp>

int main()
{
	Eigen::Matrix<float, 2, 4> m;
	m.setConstant(23.55f);

	auto m3 = m.transpose();

	auto m2 = matrix::make_random_matrix<float, 20, 20>(1000.55f, 2000.98f);
	auto m_inverse = m2.inverse();

	matrix::print_matrix(m, "matrix : ");
	matrix::print_matrix(m3, "matrix transpos :");

	std::ofstream ofs{ "matrix.txt"};
	if (!ofs.is_open()) {
		Print_(color::Green, "file is not valid") << end_;
		return -1;
	}
	matrix::print_matrix(ofs, m2, "matrix m2 : ");
	matrix::print_matrix(ofs, m_inverse, "inverse of m2 :");
	matrix::print_matrix(ofs, m_inverse * m2, "multiplication of m2 with his inverse :");
	//matrix::print_matrix(m2, "matrix 2 :");
	//matrix::print_matrix(m_inverse, "inverse of m2 :");
	//matrix::print_matrix(m_inverse * m2, "product : m2 * m2inverse ::");
	ofs.close();

	std::cout << "End..." << end_;

	std::cin.get();
	return 0;
}