#include "my_solver.h"
#include <time.h>
#include <math.h>
// HOMEWORK
void program2_3()
{
	int n = 3000;
	int i = 0;
	int j = 0;
	double u;
	double lambda[3] = { 0.5,1,1.5 };
	double x0;
	double x1;
	double x2;
	double bx;

	double x_sum = 0;;
	double x_square_sum = 0;
	double avg = 0;
	double square_avg = 0;
	double dev = 0;

	printf("n = %d\n", n);
	//////////////////////////////////////
	/////////////lambda = 0.5/////////////
	//////////////////////////////////////

	printf("lambda = 0.5\n");
	unsigned int iseed = (unsigned int)time(NULL);
	srand(iseed);
	while (i < n) {
		u = rand() / (double)RAND_MAX; // u = [0,1]
		//printf("u = %lf\n", u);
		j = 0;
		x0 = 0;
		x1 = (0 + 6) / 2;
		x2 = 6;
		bx = x0;

		while ((x0 != x1) && j <= Nmax) {
			if (((1 - exp(-lambda[0] * x0)) - u) * ((1 - exp(-lambda[0] * x1)) - u) < 0) {
				if (fabs((1 - exp(-lambda[0] * x1)) - u) < DELTA) {
					x_sum += x1;
					x_square_sum += x1 * x1;
					//printf("1 %.15lf\n", x1);
					break;
				}
				else if (fabs(x1 - bx) < EPSILON) {
					x_sum += x1;
					x_square_sum += x1 * x1;
					//printf("2 %.15lf %.15lf\n",bx, x1);
					break;
				}
				//printf("3 %.15lf\n", x0);
				x2 = x1;
				bx = x1;
				x1 = (x0 + x2) / 2;
			}
			else if (((1 - exp(-lambda[0] * x0)) - u) * ((1 - exp(-lambda[0] * x1)) - u) > 0) {
				//printf("4 %.15lf\n", x0);
				x0 = x1;
				bx = x1;
				x1 = (x0 + x2) / 2;
			}
			else {
				if ((1 - exp(-lambda[0] * x0)) - u == 0) {
				x_sum += x1;
				x_square_sum += x1 * x1;
				//printf("5 %.15lf\n", x0);
				break;
				}

				else {
					x_sum += x1;
					x_square_sum += x1 * x1;
					//printf("6 %.15lf\n", x1);
					break;
				}
			}
			if (x0 == x1) {
				x_sum += x1;
				x_square_sum += x1 * x1;
				//printf("7 %.15lf\n", x0);
			}
			j++;
		}
		i++;
	}

	avg = x_sum / n;
	square_avg = x_square_sum / n;
	dev = square_avg - (avg * avg);
	printf("The random result : AVG = %lf / DEV = %lf\n", avg, dev);
	printf("The theoretical result : AVG = %lf / DEV = %lf\n\n", 1 / lambda[0], 1 / (lambda[0] * lambda[0]));


	//////////////////////////////////////
	/////////////lambda = 1.0/////////////
	//////////////////////////////////////
	printf("lambda = 1.0\n");
	i = 0;
	x_sum = 0;;
	x_square_sum = 0;
	avg = 0;
	square_avg = 0;
	dev = 0;

	while (i < n) {
		u = rand() / (double)RAND_MAX; // u = [0,1]
		//printf("u = %lf\n", u);
		j = 0;
		x0 = 0;
		x1 = (0 + 5) / 2;
		x2 = 5;
		bx = x0;

		while ((x0 != x1) && j <= Nmax) {
			if (((1 - exp(-lambda[1] * x0)) - u) * ((1 - exp(-lambda[1] * x1)) - u) < 0) {
				if (fabs((1 - exp(-lambda[1] * x1)) - u) < DELTA) {
					x_sum += x1;
					x_square_sum += x1 * x1;
					//printf("1 %.15lf\n", x1);
					break;
				}
				else if (fabs(x1 - bx) < EPSILON) {
					x_sum += x1;
					x_square_sum += x1 * x1;
					//printf("2 %.15lf %.15lf\n",bx, x1);
					break;
				}
				//printf("3 %.15lf\n", x0);
				x2 = x1;
				bx = x1;
				x1 = (x0 + x2) / 2;
			}
			else if (((1 - exp(-lambda[1] * x0)) - u) * ((1 - exp(-lambda[1] * x1)) - u) > 0) {
				//printf("4 %.15lf\n", x0);
				x0 = x1;
				bx = x1;
				x1 = (x0 + x2) / 2;
			}
			else {
				if ((1 - exp(-lambda[1] * x0)) - u == 0) {
					x_sum += x1;
					x_square_sum += x1 * x1;
					//printf("5 %.15lf\n", x0);
					break;
				}

				else {
					x_sum += x1;
					x_square_sum += x1 * x1;
					//printf("6 %.15lf\n", x1);
					break;
				}
			}
			if (x0 == x1) {
				x_sum += x1;
				x_square_sum += x1 * x1;
				//printf("7 %.15lf\n", x0);
			}
			j++;
		}
		i++;
	}
	avg = x_sum / n;
	square_avg = x_square_sum / n;
	dev = square_avg - (avg * avg);
	printf("The random result : AVG = %lf / DEV = %lf\n", avg, dev);
	printf("The theoretical result : AVG = %lf / DEV = %lf\n\n", 1 / lambda[1], 1 / (lambda[1] * lambda[1]));


	//////////////////////////////////////
	/////////////lambda = 1.5/////////////
	//////////////////////////////////////
	printf("lambda = 1.5\n");
	i = 0;
	x_sum = 0;;
	x_square_sum = 0;
	avg = 0;
	square_avg = 0;
	dev = 0;

	while (i < n) {
		u = rand() / (double)RAND_MAX; // u = [0,1]
		j = 0;
		x0 = 0;
		x1 = (0 + 5) / 2;
		x2 = 5;
		bx = x0;

		while ((x0 != x1) && j <= Nmax) {
			if (((1 - exp(-lambda[2] * x0)) - u) * ((1 - exp(-lambda[2] * x1)) - u) < 0) {
				if (fabs((1 - exp(-lambda[2] * x1)) - u) < DELTA) {
					x_sum += x1;
					x_square_sum += x1 * x1;
					break;
				}
				else if (fabs(x1 - bx) < EPSILON) {
					x_sum += x1;
					x_square_sum += x1 * x1;
					break;
				}
				x2 = x1;
				bx = x1;
				x1 = (x0 + x2) / 2;
			}
			else if (((1 - exp(-lambda[2] * x0)) - u) * ((1 - exp(-lambda[2] * x1)) - u) > 0) {
				x0 = x1;
				bx = x1;
				x1 = (x0 + x2) / 2;
			}
			else {
				if ((1 - exp(-lambda[2] * x0)) - u == 0) {
					x_sum += x1;
					x_square_sum += x1 * x1;
					break;
				}

				else {
					x_sum += x1;
					x_square_sum += x1 * x1;
					break;
				}
			}
			if (x0 == x1) {
				x_sum += x1;
				x_square_sum += x1 * x1;
			}
			j++;
		}
		i++;
	}
	avg = x_sum / n;
	square_avg = x_square_sum / n;
	dev = square_avg - (avg * avg);
	printf("The random result : AVG = %lf / DEV = %lf\n", avg, dev);
	printf("The theoretical result : AVG = %lf / DEV = %lf\n\n", 1 / lambda[2], 1 / (lambda[2] * lambda[2]));
	
	//////////////////////////////////////
	/////////////////2-2//////////////////
	//////////////////////////////////////
	int random;
	printf("How many random numbers do you want to make? ");
	scanf("%d", &random);

	program2_2_a(random);
	program2_2_b(random);

	//////////////////////////////////////
	
	FILE *fp_r = fopen("random_event_table.txt", "r");
	double r = 0;
	fscanf(fp_r,"%d", &n);
	int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0,count_5 = 0;
	for (i = 0; i < n; i++) {
		fscanf(fp_r, "%lf", &r);
		if (r <= 0.2)
			count_1++;
		else if (r <= 0.4)
			count_2++;
		else if (r <= 0.6)
			count_3++;
		else if (r <= 0.8)
			count_4++;
		else
			count_5++;
	}
	fclose(fp_r);
	
	
	FILE* fp_w = fopen("histogram.txt", "w");
	fprintf(fp_w,"0.00 ~ 0.20 :%d\n",count_1);
	fprintf(fp_w, "0.20 ~ 0.40 : %d\n", count_2);
	fprintf(fp_w, "0.40 ~ 0.60 : %d\n", count_3);
	fprintf(fp_w, "0.60 ~ 0.80 : %d\n", count_4);
	fprintf(fp_w, "0.80 ~ 1.00 : %d\n", count_5);
	fclose(fp_w);
	
	//free(lambda);
}

// HOMEWORK
void program2_2_a(int random)
{
	__int64 start, freq, end;
	float resultTime = 0;
	/////////////////////////////////////
	CHECK_TIME_START;

	FILE* fp_r, * fp_w;

	fp_r = fopen("pdf_table.txt", "r");
	fp_w = fopen("random_event_table.txt", "w");

	int i = 0, j = 0, n;
	int sum = 0;
	int x0, x1, x2, bx;
	double py = 0;
	double h;

	fscanf(fp_r, "%d %lf", &n, &h);

	double* x = (double*)malloc(sizeof(double) * n);
	double* y = (double*)malloc(sizeof(double) * n);

	for (i = 0; i < n; i++) {
		fscanf(fp_r, "%lf %lf", &x[i], &py);
		if (i == 0)
			y[i] = py;
		else
			y[i] = y[i - 1] + py;
	}

	fprintf(fp_w, "%d\n", random);

	unsigned int iseed = (unsigned int)time(NULL);
	double u;
	srand(iseed);
	i = 0;
	while (i < random) {
		u = rand() / (double)RAND_MAX;
		bx = 0;
		x0 = 0;
		x1 = (n - 1) / 2;
		x2 = n - 1;
		j = 0;

		while ((x0 != x1) && j <= Nmax) {
			if ((y[x0] - u) * (y[x1] - u) < 0) {
				if (fabs(y[x1] - u) < DELTA) {

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
			else if ((y[x0] - u) * (y[x1] - u) > 0) {
				x0 = x1;
				bx = x1;
				x1 = (x0 + x2) / 2;
			}
			else {
				if (y[x0] - u == 0) {
					fprintf(fp_w, "%.15lf\n", x[x0]);
					break;
				}

				else {
					fprintf(fp_w, "%.15lf\n", x[x1]);
					break;
				}
			}
			if (x0 == x1)
				fprintf(fp_w, "%.15lf\n", x[x0]);
			j++;
		}
		i++;
	}
	free(x);
	free(y);

	if (fp_r != NULL) fclose(fp_r);
	if (fp_w != NULL) fclose(fp_w);

	CHECK_TIME_END(resultTime);
	/////////////////////////////////////

	printf("The program2_2_a run time is %f(ms)..\n", resultTime * 1000.0);
}

void program2_2_b(int random)
{
	__int64 start, freq, end;
	float resultTime = 0;
	/////////////////////////////////////
	CHECK_TIME_START;

	FILE* fp_r, * fp_w;

	fp_r = fopen("pdf_table.txt", "r");
	fp_w = fopen("random_event_table_2.txt", "w");

	int i = 0, j = 0, k, n;
	int sum = 0;
	int x0, x1, x2_i;
	double x2;
	double py = 0;
	double h;
	int flag = 0;

	fscanf(fp_r, "%d %lf", &n, &h);

	double* x = (double*)malloc(sizeof(double) * n);
	double* y = (double*)malloc(sizeof(double) * n);

	for (i = 0; i < n; i++) {
		fscanf(fp_r, "%lf %lf", &x[i], &py);
		if (i == 0)
			y[i] = py;
		else
			y[i] = y[i - 1] + py;
	}
	fprintf(fp_w, "%d\n", random);

	unsigned int iseed = (unsigned int)time(NULL);
	double u;
	srand(iseed);
	i = 0;
	while (i < random) {
		u = rand() / (double)RAND_MAX;
		flag = 0;
		x0 = 0;
		x1 = n / 4;
		x2_i = 0;

		for (j = 1; j <= Nmax; j++) {
			x2 = x[x1] - (y[x1] - u) * (x[x1] - x[x0]) / (y[x1] - y[x0]);
			for (k = 0; k < n - 1; k++) {
				if (x2 >= x[k] && x2 < x[k + 1]) {
					x2_i = k;
				}
			}
			if (fabs(y[x2_i] - u) < DELTA) {
				fprintf(fp_w, "%.15lf\n", x[x2_i]);
				flag = 1;
				break;
			}
			else if (fabs(x[x2_i] - x[x1]) < EPSILON) {
				fprintf(fp_w, "%.15lf\n", x[x2_i]);
				flag = 1;
				break;
			}
			x0 = x1;
			x1 = x2_i;
		}
		if (flag == 1) {
			i++;
			continue;
		}

		x0 = n / 4;
		x1 = n / 4 * 2;
		for (j = 1; j <= Nmax; j++) {
			x2 = x[x1] - (y[x1] - u) * (x[x1] - x[x0]) / (y[x1] - y[x0]);
			for (k = 0; k < n - 1; k++) {
				if (x2 >= x[k] && x2 < x[k + 1]) {
					x2_i = k;
				}
			}
			if (fabs(y[x2_i]-u) < DELTA) {
				fprintf(fp_w, "%.15lf\n", x[x2_i]);
				flag = 1;
				break;
			}
			else if (fabs(x[x2_i] - x[x1]) < EPSILON) {
				fprintf(fp_w, "%.15lf\n", x[x2_i]);
				flag = 1;
				break;
			}
			x0 = x1;
			x1 = x2_i;
		}

		if (flag == 1) {
			i++;
			continue;
		}

		x0 = n / 4 * 2;
		x1 = n / 4 * 3;
		for (j = 1; j <= Nmax; j++) {
			x2 = x[x1] - (y[x1] - u) * (x[x1] - x[x0]) / (y[x1] - y[x0]);
			for (k = 0; k < n - 1; k++) {
				if (x2 >= x[k] && x2 < x[k + 1]) {
					x2_i = k;
				}
			}
			if (fabs(y[x2_i] - u) < DELTA) {
				fprintf(fp_w, "%.15lf\n", x[x2_i]);
				flag = 1;
				break;
			}
			else if (fabs(x[x2_i] - x[x1]) < EPSILON) {
				fprintf(fp_w, "%.15lf\n", x[x2_i]);
				flag = 1;
				break;
			}
			x0 = x1;
			x1 = x2_i;
		}

		if (flag == 1) {
			i++;
			continue;
		}

		x0 = n / 4 * 3;
		x1 = n - 1;
		for (j = 1; j <= Nmax; j++) {
			x2 = x[x1] - (y[x1] - u) * (x[x1] - x[x0]) / (y[x1] - y[x0]);
			for (k = 0; k < n - 1; k++) {
				if (x2 >= x[k] && x2 < x[k + 1]) {
					x2_i = k;
				}
			}
			if (fabs(y[x2_i]-u) < DELTA) {
				fprintf(fp_w, "%.15lf\n", x[x2_i]);
				flag = 1;
				break;
			}
			else if (fabs(x[x2_i] - x[x1]) < EPSILON) {
				fprintf(fp_w, "%.15lf\n", x[x2_i]);
				flag = 1;
				break;
			}
			x0 = x1;
			x1 = x2_i;
		}
		i++;
	}
	free(x);
	free(y);

	if (fp_r != NULL) fclose(fp_r);
	if (fp_w != NULL) fclose(fp_w);
	CHECK_TIME_END(resultTime);
	/////////////////////////////////////

	printf("The program2_2_b run time is %f(ms)..\n", resultTime * 1000.0);

}