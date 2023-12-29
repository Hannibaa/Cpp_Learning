#include <iostream>
#include "MyLib/math/matrix_utility.hpp"

#define fPi    std::numbers::pi_v<float>
#define dPi    std::numbers::pi_v<double>


int main()
{
	int i = 3;
	int j = 3;
	
	Eigen::Matrix<std::string, 2, 2> Mstr;

	Mstr(0, 0) = "hello";
	Mstr(0, 1) = "world";
	Mstr(1, 0) = "rig";
	Mstr(1, 1) = "room";

	Eigen::MatrixXd m(i, j);
	auto M	= matrix::make_matrixd(i, j, [](int i, int j)->float {return std::sinf(i * j); });

	auto Mx = Eigen::AngleAxisf(0.25f * fPi  , Eigen::Vector3f::UnitX());
	auto My = Eigen::AngleAxisf(0.25f * fPi  , Eigen::Vector3f::UnitY());
	auto Mz = Eigen::AngleAxisf(0.25f * fPi  , Eigen::Vector3f::UnitZ());
	

	m = matrix::make_matrixd(i, j, [](int i, int j) {return std::log(i * i + j * j + 1); });

	Eigen::VectorXf vf = Eigen::VectorXf::Random(6);
	Eigen::VectorXi vi = Eigen::VectorXi::Random(2);

	
	Eigen::VectorXd v(3);

	v << 3.0, 4.0, 5.0;

	auto Mv = Eigen::AngleAxisd(0.5f * fPi, v);




	Print_(color::Green, "New program") << end_;
	matrix::print_matrix(m, "matrix m :");
	matrix::print_matrix(M, "matrix M :");
	matrix::print_matrix(m * M, "matrix m*M :");
	matrix::print_matrix(v, "vector v :");
	matrix::print_matrix(vf, "vector vf :");
	matrix::print_matrix(vi, "vector vi :");
	matrix::print_matrix(Mx.matrix(), "Rotation Axe Ox :");
	matrix::print_matrix(My.matrix(), "Rotation Axe Oy :");
	matrix::print_matrix(Mz.matrix(), "Rotation Axe Oz :");
	matrix::print_matrix(Mv.matrix(), "Rotation Axe v :");
	matrix::print_matrix(Mstr, "String matrix Mstr :");


	std::cin.get();
	return 0;
}