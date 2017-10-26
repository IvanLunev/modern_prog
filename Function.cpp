#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "Function.h"
#include <string>
#include <math.h>
#include "r32m.h"
#include <ctime>

using namespace Eigen;
using namespace std;


VectorXd Function::optimization(double eps) {

	VectorXd V = V0;
	VectorXd Gr(dim);

	int i = 0;

	while ((Gr = Gradient(V)).norm() > eps) {
		++i;
		V = V - Hessian(V).colPivHouseholderQr().solve(alpha*Gr);
	}
	return V;
}


VectorXd Function::rand_vec(VectorXd& left, VectorXd& right) const {

	VectorXd V(dim);

	for (int i = 0; i < dim; ++i) {
		V(i) = left(i) + rnunif()*(right(i) - left(i));
	}

	return V;
}



void Function::get_area(VectorXd& left, VectorXd& right)  {

	l = left;
	r = right;
}





void Function::start(VectorXd V){

	V0 = V;
}


VectorXd Function::step(VectorXd V_old) const {

	VectorXd V(dim);


	double epsilon;

	VectorXd l1 = l;
	VectorXd r1 = r;

	VectorXd l0 = l;
	VectorXd r0 = r;

	epsilon = min(min(((V_old - l).cwiseAbs()).minCoeff(), ((r - V_old).cwiseAbs()).minCoeff()), ((r - l) / 100).maxCoeff());

	double e;

	e = rnunif();
	if (e < p) {
		V = rand_vec(l0, r0);
	}
	else {
		l1 = (V_old.array() - epsilon).matrix();
		r1 = (V_old.array() + epsilon).matrix();
		V = rand_vec(l1, r1);
	}

	return V;
}


bool Function::stop(int i_suc_iter, int j_iter) const {
	return(i_suc_iter < suc_iter_num && j_iter < max_iter);
}







VectorXd Function::random_search(double p0, int suc_iter_num0, int max_iter0) {

	rninit(time(0));

	p = p0;

	suc_iter_num = suc_iter_num0;
		max_iter = max_iter0;


	VectorXd V_n(dim);
	VectorXd V(dim);

		
	V = V0;



	int i = 0;
	int j = 0;
	while (stop(i,j)) {
		++j;
		
	
		V_n = step(V);
		if (fun_value(V) > fun_value(V_n)) {
			V = V_n;

			++i;

		}
	}

	return V;
}
