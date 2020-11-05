#include "my_solver.h"

extern float (*_sp_f)(float);
extern float (*_sp_fp)(float);

/*********************************************
  Secant Method
**********************************************/
float sp_program1_2(float x0, float x1) {
    float _x0, _x1, _x2;

    printf("i       xn1         |f(xn1)|        |xn1-xroot|\n");
    _x0 = x0;
    _x1 = x1;
    for (int i = 0; i < Nmax; i++) {
        printf("%d   %e   %e    %e\n", i, _x0, fabs(_sp_f(_x0)), fabs(_x0 - sqrt(_x0)));

        //x1 = x0 - _f(x0) / _fp(x0);
        _x2 = _x1 - _sp_f(_x1) * (_x1 - _x0) / (_sp_f(_x1) - _sp_f(_x0));
        if (fabs(_x2) < DELTA)
            break;
        else if (fabs(_x2 - _x1) < EPSILON)
            break;
        _x0 = _x1;
        _x1 = _x2;
    }
    return _x2;
}
