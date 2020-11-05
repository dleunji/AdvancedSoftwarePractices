#include "my_solver.h"

#define SOLNUMS 2
#define MATCOLS SOLNUMS
#define MATROWS SOLNUMS
#define TOLERANCE 0.0000001

void fcn3_7(int* n, double* x, double* fvec, int* iflag)
{
	/********************************/

	fvec[0] = 2.0 * x[0] * x[0] * x[0] - 12.0 * x[0] - x[1] - 1.0;
	fvec[1] = 3.0 * x[1] * x[1] - 6.0 * x[1] - x[0] - 3.0;

	/********************************/
}

void practice3_7(void)
{
	int n = SOLNUMS;
	double x[SOLNUMS] = { -4.0, 5.0 };	//need to initilize x0
	double fvec[SOLNUMS];
	double tol = TOLERANCE;
	int info;
	double wa[(SOLNUMS * (3 * SOLNUMS + 13)) / 2];
	int lwa = (SOLNUMS * (3 * SOLNUMS + 13)) / 2;

	FILE* fp_w = fopen("roots_3-7.txt", "w");
	if (fp_w == NULL) {
		printf("%s file open error...\n", "roots_3-7.txt");
		return;
	}

	/********************************/

	for (double x_ = -4.0; x_ <= 4.0; x_ += 1.0) {
		for (double y_ = 5.0; y_ >= -5.0; y_ -= 1.0) {
			x[0] = x_;
			x[1] = y_;

			hybrd1_(fcn3_7, &n, x, fvec, &tol, &info, wa, &lwa);
			fprintf(fp_w, "The x : %lf %lf\n", x[0], x[1]);

			fprintf(fp_w, "Applying X and Y...\n");
			fprintf(fp_w, "The gap with the result of f1 : %lf\n", fabs(fvec[0]));
			fprintf(fp_w, "The gap with the result of f2 : %lf\n\n", fabs(fvec[1]));
		}
	}

	/********************************/

	fclose(fp_w);
}