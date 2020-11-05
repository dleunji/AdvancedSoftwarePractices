#include "my_solver.h"

extern double (*_f)(double);
extern double (*_fp)(double);

/*********************************************
  Bisection Method
**********************************************/
double program1_3(double x0, double x2) {

    double x1 = x0 + x2 / 2;
    double bx = x0;
    int i = 1;
    printf("i       xn1         |f(xn1)|        |xn1-xroot|\n");

    while ((x0 != x1) && i<=Nmax) {
        printf("%d   %.10e   %.10e    %.10e\n", i++, bx, fabs(_f(bx)), fabs(bx - sqrt(bx)));
        if (_f(x0) * _f(x1) < 0) {
            if (fabs(x1) < DELTA) 
                return x1;

            else if (fabs(x1 - bx) < EPSILON)
                return x1;

            x2 = x1;
            bx = x1;
            x1 = (x0 + x2) / 2;
        }
        else if (_f(x0) * _f(x1) > 0) {
            x0 = x1;
            bx = x1;
            x1 = (x0 + x2) / 2;
        }
        else {
            if (_f(x0) == 0)
                return x0;
            else
                return x1;
        }
    }


}