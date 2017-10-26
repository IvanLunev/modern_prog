#pragma once

using namespace Eigen;
using namespace std;


class Function
{
protected:
	VectorXd V0;
	double alpha = 1;
	int dim;
	double p=0.8;

	int suc_iter_num;
	int max_iter;

	VectorXd l;
	VectorXd r;

	virtual double fun_value(VectorXd& v)const = 0;
	virtual MatrixXd Hessian(VectorXd& v) const = 0;
	virtual VectorXd Gradient(VectorXd& v) const = 0;

	virtual VectorXd rand_vec(VectorXd& left, VectorXd& right) const;

	
public:
	virtual void get_area(VectorXd& left, VectorXd& right);

	virtual VectorXd random_search(double p0=0.8, int suc_iter_num0 = 50, int max_iter0=50000);
	virtual VectorXd optimization(double eps=0.001);
	virtual string func_name() const = 0;

	virtual void start(VectorXd V);
	virtual VectorXd step(VectorXd V_old) const;
	virtual bool  stop(int i_suc_iter, int j_iter) const;
};







/////////////////////////////////////////////////////////////////  Function_n


//
//
//template<class Mat, class Vec>
//class Function_n
//{
//protected:
//	Vec V0;
//	double eps = 0.001;
//	double alpha = 1;
//
//public:
//	virtual double fun_value(Vec& v)const = 0;
//	Vec random_search(Vec& l, Vec& r, double p = 0.8);
//	Vec optimization();
//	virtual Mat Hessian(Vec& v)const = 0;
//	virtual Vec Gradient(Vec& v)const = 0;
//	virtual string func_name() const = 0;
//};
//
//
//
//
//////////////////////////////////////////   FUN1_n
//
//
//template<class Mat, class Vec>
//class FUN1_n :public Function_n<Mat,Vec>
//{
//protected:
//
//public:
//	FUN1_n(Vec& v);
//	double fun_value(Vec & v) const override;
//	Mat Hessian(Vec& v) const override;
//	Vec Gradient(Vec& v)const  override;
//	string func_name() const override;
//};
//
//
//
//
//
//
//////////////////////////////////////////     FUN2_n
//
//
//
//
//template<class Mat, class Vec>
//class FUN2_n :public Function_n<Mat, Vec>
//{
//protected:
//
//public:
//	FUN2_n(Vec& v);
//	double fun_value(Vec & v) const override;
//	Mat Hessian(Vec& v) const override;
//	Vec Gradient(Vec& v)const  override;
//	string func_name() const override;
//};
//
//
//
//
//
//////////////////////////////////////////     FUN3_n
//
//
//
//
//template<class Mat, class Vec>
//class FUN3_n :public Function_n<Mat, Vec>
//{
//protected:
//
//public:
//	FUN3_n(Vec& v);
//	double fun_value(Vec & v) const override;
//	Mat Hessian(Vec& v) const override;
//	Vec Gradient(Vec& v)const  override;
//	string func_name() const override;
//};
//
//
//
//
//////////////////////////////////////////  Function_n::optimization
//
//
//
//template<class Mat, class Vec>
//Vec Function_n<Mat, Vec>::optimization() {
//
//	Vec V = V0;
//	Vec Gr;
//
//	int i = 0;
//
//	while ((Gr = Gradient(V)).norm() > eps) {
//		++i;
//		cout << i << "\n" << endl;
//		V = V - Hessian(V).colPivHouseholderQr().solve(alpha*Gr);
//		cout << V <<"\n\n"<< endl;
//	}
//	return V;
//}
//
//
//////////////////////////////////////////  Function_n::random_search
//
//
//
//template<class Mat, class Vec>
//Vec Function_n<Mat, Vec>::random_search(Vec& l, Vec& r,double p=0.8) {
//
//	rninit(time(0));
//	double e;
//
//	Vec V_n;
//
//	Vec V = (l+r)/2;
//	if (V0==V) V =(V+l)/2;
//
//	int n = V.rows();
//
//	double epsilon;
//
//
//	int i = 0;
//	while ((((V-V0).cwiseAbs()).maxCoeff()> eps) && (i<50000)) {
//		++i;
//		epsilon = min(min(((V-l).cwiseAbs()).minCoeff(), ((r-V).cwiseAbs()).minCoeff()), ((r-l)/100).maxCoeff());
//
//
//		e = rnunif();
//		if (e < p) {
//			for (int i = 0; i < n; ++i) {
//				V_n(i) = l(i) + rnunif()*(r(i) - l(i)) ;
//			}
//		}
//		else {
//			for (int i = 0; i < n; ++i) {
//				V_n(i) = rnunif() * 2 - 1;
//				V_n(i) = V(i) + epsilon*V_n(i);
//			}
//		}
//
//		if (fun_value(V) > fun_value(V_n)) {
//			V0 = V;
//			V = V_n;
//			cout << "V=" << V << "\n" << "||V-V0|| = "<< ((V - V0).cwiseAbs()).maxCoeff() << "\n" << endl;
//		}
//	}
//
//	cout << "i="<< i << "\n"<< endl;
//	return V;
//}
//
//
//
/////////////////////////////////////////////////     FUN1_n
//
//
//template<class Mat, class Vec>
//double FUN1_n<Mat, Vec>::fun_value(Vec& v)const {
//	double k;
//	k= v(0)*v(0)*v(0) + 3*v(0)*v(1)*v(1) - 15*v(0) - 12*v(1);
//	return k;
//}
//
//
//template<class Mat, class Vec>
//Mat FUN1_n<Mat, Vec>::Hessian(Vec& v)const {
//	Mat k;
//	k << 6 * v(0), 6 * v(1), 6 * v(1), 6 * v(0);
//	return k;
//}
//
//template<class Mat, class Vec>
//Vec FUN1_n<Mat, Vec>::Gradient(Vec& v)const {
//	Vec k(3 * (v(0)*v(0) + v(1)*v(1)) - 15, 6 * v(0)*v(1) - 12);
//	return k;
//}
//
//template<class Mat, class Vec>
//FUN1_n<Mat, Vec>::FUN1_n(Vec& v){
//	V0 = v;
//}
//
//template<class Mat, class Vec>
//string FUN1_n<Mat, Vec>::func_name() const {
//	return std::string("x^3+3xy^2-15x-12y");
//}
//
// 
/////////////////////////////////////////////////     FUN2_n
//
//template<class Mat, class Vec>
//double FUN2_n<Mat, Vec>::fun_value(Vec& v)const {
//	double k;
//	k = 100*(v(1) - v(0))*(v(1)-v(0)) + (1 - v(0)) *(1-v(0));
//	return k;
//}
//
//
//template<class Mat, class Vec>
//Mat FUN2_n<Mat, Vec>::Hessian(Vec& v)const {
//	Mat k;
//	k << 202,-200,-200,200;
//	return k;
//}
//
//template<class Mat, class Vec>
//Vec FUN2_n<Mat, Vec>::Gradient(Vec& v)const {
//	Vec k(-200*v(1)+202*v(0)-2, 200*v(1)-200*v(0));
//	return k;
//}
//
//template<class Mat, class Vec>
//FUN2_n<Mat, Vec>::FUN2_n(Vec& v) {
//	V0 = v;
//}
//
//template<class Mat, class Vec>
//string FUN2_n<Mat, Vec>::func_name() const {
//	return std::string("100(y-x)^2+(1-x)^2");
//}
//
//
/////////////////////////////////////////////////     FUN3_n
//
//template<class Mat, class Vec>
//double FUN3_n<Mat, Vec>::fun_value(Vec& v)const {
//	double k;
//	k = 100 * (v(1) - v(0)*v(0)*v(0))*(v(1) - v(0)*v(0)*v(0)) + (1 - v(0)) *(1 - v(0));
//	return k;
//}
//
//
//template<class Mat, class Vec>
//Mat FUN3_n<Mat, Vec>::Hessian(Vec& v)const {
//	Mat k;
//	k << -1200*v(0)*v(1)+3000*pow(v(0),4)+2, -600*pow(v(0),2), -600 * pow(v(0), 2), 200;
//	return k;
//}
//
//template<class Mat, class Vec>
//Vec FUN3_n<Mat, Vec>::Gradient(Vec& v)const {
//	Vec k(-600 * v(1)*v(0)*v(0) + 600 * pow(v(0),5)+2*v(0) - 2, 200 * v(1) - 200 * pow(v(0),3));
//	return k;
//}
//
//template<class Mat, class Vec>
//FUN3_n<Mat, Vec>::FUN3_n(Vec& v) {
//	V0 = v;
//}
//
//template<class Mat, class Vec>
//string FUN3_n<Mat, Vec>::func_name() const {
//	return std::string("100(y-x^3)^2+(1-x)^2");
//}