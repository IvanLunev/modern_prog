// modern_prog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "FUN1.h"
#include "FUN2.h"
#include "FUN3.h"

using namespace Eigen;
using namespace std;

int main()
{
	//Vector2d V(-1.2, 1);
	//Vector2d l(-2, -2);
	//Vector2d r(2, 2);

	//FUN3_n<Matrix2d, Vector2d> FF(V);

	cout << "Choose your method: \n" << "1 - Newton \n" << "2 - random search \n" << endl;

	int method;

	cin >> method;

	cout << "\n Choose your function: \n" << "1 - x^3+3xy^2-15x-12y \n" << "2 - 100(y-x)^2+(1-x)^2 \n" << "3 - 100(y-x^3)^2+(1-x)^2 \n" << endl;

	int choose;

	cin >> choose;

	int k ;

	cout << "\n Dimension: \n" << endl;

	cin >> k;

	VectorXd V(k);
	VectorXd l(k);
	VectorXd r(k);

	cout << "\n Initial vector: \n" << endl;

	double * Vec = new double[k];

	for(int i=0;i<k;++i)
	cin >> Vec[i];

	for (int i = 0; i<k; ++i)
		V(i)=Vec[i];





	delete Vec;

	Function * FF;
	switch (choose)
	{
	case 1: {
		FF = new FUN1(V);
		break;
	  }
	case 2: {
		FF = new FUN2(V);
		break;
	  }
	case 3: {
		FF = new FUN3(V);
		break;
	  }
	}




	switch (method)
	{
	case 1: {
		cout << "\n Accuracy: \n" << endl;
		double eps;
		cin >> eps;
		std::cout <<  "\n Function: \n"<< FF->func_name() << "\n\n" << "Min: \n" << FF->optimization(eps) << std::endl;

		break;
	}
	case 2: {
		cout << "\n Choose your area: \n" << endl;
		cout << "left:" << endl;

		for (int i = 0; i<k; ++i)
			cin >> Vec[i];

		for (int i = 0; i<k; ++i)
			l(i) = Vec[i];


		cout << "right:" << endl;

		for (int i = 0; i<k; ++i)
			cin >> Vec[i];

		for (int i = 0; i<k; ++i)
			r(i) = Vec[i];

		FF->get_area(l, r);


		cout << "\n Probability: \n" << endl;
		double p;
		cin >> p;

		cout << "\n Number of uccessful iteration: \n" << endl;
		double suc_iter_num;
		cin >> suc_iter_num;

		cout << "\n Max iteration: \n" << endl;
		double max_iter;
		cin >> max_iter;

		std::cout <<"\n Function: \n"<< FF->func_name() << "\n\n" <<"Min: \n"<< FF->random_search(p, suc_iter_num, max_iter) << std::endl;

		break;
	}
  }



	delete FF;






	
//	VectorXd V(2);
//	V<<-1.2, 1;

//	VectorXd l(2);
//	l<< -2, -2;

//	VectorXd r(2);
//	r << 2, 2;


//	FUN3 FF(V);

//	double p = 0.8;
//	int suc_iter_num = 50;
//	int max_iter = 50000;

//	FF.get_area(l, r);

//	std::cout << FF.func_name()<<"\n\n"<<FF.random_search(p, suc_iter_num, max_iter) <<std::endl;
	system("pause");
	return(0);
}
