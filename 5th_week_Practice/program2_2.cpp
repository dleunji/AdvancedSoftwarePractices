#include "my_solver.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

void program2_2()
{
	FILE* fp_r, *fp_w;

	fp_r = fopen("pdf_table.txt", "r");
	fp_w = fopen("random_event_table.txt", "w");

	/***************************************************/
	int i = 0,j = 0, random,n;
	int sum = 0;
	int x0, x1, x2, bx;
	double py = 0;
	double h;

	fscanf(fp_r, "%d %lf", &n, &h);

	double* x = (double*)malloc(sizeof(double) * n);
	double* y = (double*)malloc(sizeof(double) * n);

	for (i = 0; i < n; i++) {
		fscanf(fp_r,"%lf %lf", &x[i], &py);
		if (i == 0)
			y[i] = py;
		else
			y[i] = y[i - 1] + py;
	}

	scanf("%d", &random);
	fprintf(fp_w,"%d\n", random);

	unsigned int iseed = (unsigned int)time(NULL);
	double u;
	srand(iseed);
	i = 0;
	while (i < random) {
		u = rand() /(double) RAND_MAX;
		printf("%lf\n", u);
		bx = 0;
		x0 = 0;
		x1 = (n - 1)/ 2;
		x2 = n - 1;
		j = 0;
		
		while ((x0 != x1) && j <= Nmax) {
			if ((y[x0] - u) * (y[x1] - u) < 0) {
				if (fabs(y[x1]-u) < DELTA) {
					
					fprintf(fp_w, "%.15lf\n", x[x1]);
					break;
				}
				else if (fabs(x[x1] - x[bx]) < EPSILON) {
					
					fprintf(fp_w, "%.15lf\n", x[x1]);
					break;
				}
				x2 = x1;
				bx = x1;
				x1 = (x0 + x2) / 2;
			}
			else if ((y[x0] - u) *(y[x1] - u) > 0) {
				x0 = x1;
				bx = x1;
				x1 = (x0 + x2) / 2;
			}
			else {
				printf("5 %lf %lf %lf\n", y[x0], y[x1], y[x2]);
				if (y[x0] - u == 0) {
					fprintf(fp_w, "%.15lf\n", x[x0]);
					break;
				}
					
				else {
					fprintf(fp_w, "%.15lf\n",x[x1]);
					break;
				}
			}
			if (x0 == x1)
				fprintf(fp_w, "%.15lf\n", x[x0]);
			j++;
		}
		i++;
		printf("\n");
	}
	free(x);
	free(y);



	/***************************************************/

	if (fp_r != NULL) fclose(fp_r);
	if (fp_w != NULL) fclose(fp_w);
}
