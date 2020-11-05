#include <stdio.h>
#include <math.h>

#define _USE_MATH_DEFINES

#define PI 3.1415926535
#define l 89
#define h 49
#define D 55
#define beta 11.5

double _f1(double x) {
	/*
	double result;
	x = x * PI / 180;
	
	double A = l * sin(beta * PI / 180);
	double B = l * cos(beta * PI / 180);
	double C = (h + 0.5 * D) * sin(beta * PI / 180) - 0.5 * D * tan(beta * PI / 180);
	double E = (h + 0.5 * D) * cos(beta * PI / 180) - 0.5 * D;

	result = A * sin(x) * cos(x) + B * sin(x) * sin(x) - C * cos(x) - E * sin(x);
	return result;
	*/
	//return x * x - 4 * x + 4 - log(x); //PROB 1-1
	//return pow(x, 4) - 11.0 * pow(x, 3) + 42.35 * pow(x, 2) - 66.55 * x + 35.1384;
	return log(x) - 1;
}

double _fp1(double x) {
	/*
	double result;
	x = x * PI / 180;

	double A = l * sin(beta * PI / 180);
	double B = l * cos(beta * PI / 180);
	double C = (h + 0.5 * D) * sin(beta * PI / 180) - 0.5 * D * tan(beta * PI / 180);
	double E = (h + 0.5 * D) * cos(beta * PI / 180) - 0.5 * D;

	result = A * (cos(x) * cos(x) - sin(x) * sin(x)) + 2 * B * sin(x) * cos(x) + C * sin(x) - E * cos(x);
	return result;
	*/
	//return 2 * x - 1 / x;   //PROB 1-1
	//return 4 * pow(x, 3) - 3 * 11.0 * pow(x, 2) + 2 * 42.35 * x - 66.55;
	return 1 / x;
}


