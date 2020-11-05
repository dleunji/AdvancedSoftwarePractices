#include "my_solver.h"

extern double program1_1(double x0); // Newton-Raphson Method
extern double program1_2(double x0, double x1); // Secant Method
extern double program1_3(double x0, double x2); // Bisection Method

extern float sp_program1_1(float x0); // Newton-Raphson Method
extern float sp_program1_2(float x0, float x1); // Secant Method

double (*_f)(double);
double (*_fp)(double);

float (*_sp_f)(float);
float (*_sp_fp)(float);

int main() {
	double x0 = 2.6;
	//double x1 = 4.0;
	FILE* fp;
	fp = fopen("result.txt", "w");

	_f = _f1;
	_fp = _fp1;

	_sp_f = _sp_f1;
	_sp_fp = _sp_fp1;

	/////////PROB 1-1/////////////

	//program1_1(x0);
	//program1_2(x0,x1);
	//program1_3(x0,x1);

	/////////PROB 1-2/////////////
	/*
	x0 = program1_1(1.02);
	if (x0 > 1.02 && x0 < 1.48)
		printf("%lf\n", x0);
	else {
		x0 = program1_1(1.48);
		printf("%lf\n", x0);
	}

	x0 = program1_1(1.95);
	if (x0 > 1.95 && x0 < 2.37)
		printf("%lf\n", x0);
	else {
		x0 = program1_1(2.37);
		printf("%lf\n", x0);
	}

	x0 = program1_1(3.11);
	if (x0 > 3.11 && x0 < 3.73)
		printf("%lf\n", x0);
	else {
		x0 = program1_1(3.73);
		printf("%lf\n", x0);
	}

	x0 = program1_1(3.83);
	if (x0 > 3.83 && x0 < 4.61)
		printf("%lf\n", x0);
	else {
		x0 = program1_1(4.61);
		printf("%lf\n", x0);
	}
	*/

	/////////PROB 1-4/////////////
	program1_1(2.8);
	sp_program1_1(2.8);

	/////////과제 2/////////////
	//program1_1(x0);
	

	



	fclose(fp);
	system("pause");
}
