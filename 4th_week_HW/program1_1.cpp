
#include <math.h>
#include "my_solver.h"

extern double (*_f)(double);
extern double (*_fp)(double);


/*********************************************
  Newton-Rapson Method
**********************************************/
double program1_1(double x0) {
    double x, x1;
    x = x0;

    printf("i       xn1         |f(xn1)|        |xn1-xroot|\n");

    for (int i = 1; i <= Nmax; i++) {
        printf("%d   %.10e   %.10e    %.10e\n", i, x, fabs(_f(x)), fabs(x - sqrt(x)));

        x1 = x - _f(x) / _fp(x);

        if (fabs(x1) < DELTA)
            break;
        else if (fabs(x1 - x) < EPSILON)
            break;
        x = x1;
  
    }
    return x1;
}
