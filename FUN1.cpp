#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "FUN1.h"
#include <string>

using namespace Eigen;
using namespace std;

FUN1::FUN1(VectorXd& v) {
	dim = v.rows();
	V0 = v;
};

MatrixXd FUN1::Hessian(VectorXd& v) const {
	MatrixXd k(dim, dim);
	k << 6 * v(0), 6 * v(1), 6 * v(1), 6 * v(0);
	return k;
}

VectorXd FUN1::Gradient(VectorXd& v) const {
	VectorXd k(dim);
	k << 3 * (v(0)*v(0) + v(1)*v(1)) - 15, 6 * v(0)*v(1) - 12;
	return k;
}

string FUN1::func_name() const {
	return std::string("x^3+3xy^2-15x-12y");
}


double FUN1::fun_value(VectorXd& v)const {
	double k;
	k = v(0)*v(0)*v(0) + 3 * v(0)*v(1)*v(1) - 15 * v(0) - 12 * v(1);
	return k;
}

