#include "my_solver.h"

void program2_1()
{
	FILE* fp_r, *fp_w;
	__int64 start, freq, end;
	float resultTime = 0;
	

	fp_r = fopen("sampling_table.txt", "r");
	if (fp_r == NULL) {
		printf("input file not found....\n");
		exit(0);
	}

	fp_w = fopen("pdf_table.txt", "w");

	/***************************************************/
	int n;
	double h, integration;
	double sum = 0;
	double xd;

	fscanf(fp_r,"%d %f", &n, &h);
	
	double *x = (double *)malloc(sizeof(double)*n);
	double *y = (double*)malloc(sizeof(double)*n);

	for (int i = 0; i < n; i++) {
		fscanf(fp_r, "%lf %lf", &x[i], &y[i]);
	}
	xd = x[n - 1] - x[0];

	for (int i = 0; i < n; i++) {
		x[i] = (x[i] - x[0]) / xd;
	}
	h = x[n - 1] - x[0] / (n - 1);

	integration = y[0] + y[n-1];

	for (int i = 1; i < n-1; i++) {
		integration += 2 * y[i];
	}

	integration = integration * h;
	integration /= 2;
	fprintf(fp_w, "%d %lf\n", n, h);
	for (int i = 0; i < n; i++) {
		y[i] /= integration;
		fprintf(fp_w, "%lf %lf\n", x[i], y[i]);
	}

	//////½Ç½À 2-1
	for (int i = 0; i < n; i++) {
		sum += y[i];
	}
	printf("*** Integrating the pdf from 0.0 to 1.0 = %lf\n", sum);
	sum = 0;

	for (int i = 0; i < n; i++) {
		if (x[i] > 0.25)
			break;
		sum += y[i];
	}
	printf("*** Integrating the pdf from 0.0 to 0.25 = %lf\n", sum);
	sum = 0;

	for (int i = 0; i < n; i++) {//0.25 ~ 0.5
		if (x[i] >= 0.25 && x[i] <= 0.5)
			sum += y[i];
		else if (x[i] > 0.5)
			break;
	}
	printf("*** Integrating the pdf from 0.25 to 0.5 = %lf\n", sum);
	sum = 0;

	for (int i = 0; i < n; i++) {//0.25 ~ 0.5
		if (x[i] >= 0.5 && x[i] <= 0.75)
			sum += y[i];
		else if (x[i] > 0.75)
			break;
	}
	printf("*** Integrating the pdf from 0.5 to 0.75 = %lf\n", sum);
	sum = 0;

	for (int i = 0; i < n; i++) {//0.75 ~ 0.1
		if (x[i] >= 0.75)
			sum += y[i];
	}
	printf("*** Integrating the pdf from 0.75 to 1.0 = %lf\n", sum);


	free(x);
	free(y);
	/***************************************************/

	if (fp_r != NULL) fclose(fp_r);
	if (fp_w != NULL) fclose(fp_w);
}
