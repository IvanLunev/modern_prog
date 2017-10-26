#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "FUN2.h"
#include <string>

using namespace Eigen;
using namespace std;


FUN2::FUN2(VectorXd& v) {
	V0 = v;
	dim = v.rows();
}

double FUN2::fun_value(VectorXd& v)const {
	double k;
	k = 100 * (v(1) - v(0))*(v(1) - v(0)) + (1 - v(0)) *(1 - v(0));
	return k;
}



MatrixXd FUN2::Hessian(VectorXd& v)const {
	MatrixXd k(dim, dim);
	k << 202, -200, -200, 200;
	return k;
}


VectorXd FUN2::Gradient(VectorXd& v)const {
	VectorXd k(dim);
	k << -200 * v(1) + 202 * v(0) - 2, 200 * v(1) - 200 * v(0);
	return k;
}



string FUN2::func_name() const {
	return std::string("100(y-x)^2+(1-x)^2");
}
