#include "my_solver.h"

extern float (*_sp_f)(float);
extern float (*_sp_fp)(float);

/*********************************************
  Newton-Rapson Method
**********************************************/
float sp_program1_1(float x0) {
    float x = x0, x1;

    printf("i       xn1         |f(xn1)|        |xn1-xroot|\n");

    for (int i = 1; i <= Nmax; i++) {
        printf("%d   %.10e   %.10e    %.10e\n", i, x, fabs(_sp_f(x)), fabs(x - sqrt(x)));
        x1 = x - _sp_f(x) / _sp_fp(x);

        if (fabs(x1) < DELTA)
            break;
        else if (fabs(x1 - x) < EPSILON)
            break;
        x = x1;

    }
    return x1;

}
