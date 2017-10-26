#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "FUN3.h"
#include <string>

using namespace Eigen;
using namespace std;


double FUN3::fun_value(VectorXd& v)const {
	double k;
	k = 100 * (v(1) - v(0)*v(0)*v(0))*(v(1) - v(0)*v(0)*v(0)) + (1 - v(0)) *(1 - v(0));
	return k;
}



MatrixXd FUN3::Hessian(VectorXd& v)const {
	MatrixXd k(dim, dim);
	k << -1200 * v(0)*v(1) + 3000 * pow(v(0), 4) + 2, -600 * pow(v(0), 2), -600 * pow(v(0), 2), 200;
	return k;
}


VectorXd FUN3::Gradient(VectorXd& v)const {
	VectorXd k(dim);
	k << -600 * v(1)*v(0)*v(0) + 600 * pow(v(0), 5) + 2 * v(0) - 2, 200 * v(1) - 200 * pow(v(0), 3);
	return k;
}


FUN3::FUN3(VectorXd& v) {
	V0 = v;
	dim = v.rows();
}


string FUN3::func_name() const {
	return std::string("100(y-x^3)^2+(1-x)^2");
}

