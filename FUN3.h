#pragma once

#include "Function.h"


using namespace Eigen;
using namespace std;

class FUN3 :public Function
{
protected:
	double fun_value(VectorXd & v) const override;
	MatrixXd Hessian(VectorXd& v) const override;
	VectorXd Gradient(VectorXd& v)const  override;

public:
	FUN3(VectorXd& v);
	string func_name() const override;
};


