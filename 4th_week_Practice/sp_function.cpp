#define _USE_MATH_DEFINES
#include <math.h>

float _sp_f1(float x) {

	//return x * x - 4 * x + 4 - log(x); //PROB 1-1
	//return pow(x, 4) - 11.0 * pow(x, 3) + 42.35 * pow(x, 2) - 66.55 * x + 35.1384; //PROB 1-2
	return log(x) - 1;  //PROB 1-4
}

float _sp_fp1(float x) {
	//return 2 * x - 1 / x;   //PROB 1-1
	//return 4 * pow(x, 3) - 3 * 11.0 * pow(x, 2) + 2 * 42.35 * x - 66.55;  //PROB 1-2
	return 1 / x;       //PROB 1-4
}
