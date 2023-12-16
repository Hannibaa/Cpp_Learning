#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include <numbers>
#include <Eigen/Dense>


#define fPi    std::numbers::pi_v<float>
#define dPi    std::numbers::pi_v<double>

template<typename NumberType, typename Matrix>
Matrix convert_to(const Matrix& m) {

}

template<typename _Func> // we can added some concepts about function f.
Eigen::MatrixXd make_matrixd(int i, int j, _Func f) {

	Eigen::MatrixXd m(i,j);

	for (int k = 0; k != i; ++k)
		for (int l = 0; l != j; ++l)
			m(k, l) = f(k,l);

	return m;
}

template<typename Matrix, typename Comment>
void print_matrix(const Matrix& m, const Comment comment = "") {

	Print_(color::Green, comment) << end_;
	Print_(color::Fuchsia, "{");
	Print_(color::Red, m) << end_;
	Print_(color::Fuchsia, "}") << end_;

}

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
	auto M	= make_matrixd(i, j, [](int i, int j)->float {return std::sinf(i * j); });

	auto Mx = Eigen::AngleAxisf(0.25f * fPi  , Eigen::Vector3f::UnitX());
	auto My = Eigen::AngleAxisf(0.25f * fPi  , Eigen::Vector3f::UnitY());
	auto Mz = Eigen::AngleAxisf(0.25f * fPi  , Eigen::Vector3f::UnitZ());
	

	m = make_matrixd(i, j, [](int i, int j) {return std::log(i * i + j * j + 1); });

	Eigen::VectorXf vf = Eigen::VectorXf::Random(6);
	Eigen::VectorXi vi = Eigen::VectorXi::Random(2);

	
	Eigen::VectorXd v(3);

	v << 3.0, 4.0, 5.0;

	auto Mv = Eigen::AngleAxisd(0.5f * fPi, v);




	Print_(color::Green, "New program") << end_;
	print_matrix(m, "matrix m :");
	print_matrix(M, "matrix M :");
	print_matrix(m * M, "matrix m*M :");
	print_matrix(v, "vector v :");
	print_matrix(vf, "vector vf :");
	print_matrix(vi, "vector vi :");
	print_matrix(Mx.matrix(), "Rotation Axe Ox :");
	print_matrix(My.matrix(), "Rotation Axe Oy :");
	print_matrix(Mz.matrix(), "Rotation Axe Oz :");
	print_matrix(Mv.matrix(), "Rotation Axe v :");
	print_matrix(Mstr, "String matrix Mstr :");


	std::cin.get();
	return 0;
}