#include <stdio.h>
#include <string.h>
#include <random>
#include <time.h>

#include <math.h>
#include <time.h>
#include <Windows.h>

__int64 start, freq, end;
#define CHECK_TIME_START QueryPerformanceFrequency((LARGE_INTEGER*)&freq); QueryPerformanceCounter((LARGE_INTEGER*)&start)
#define CHECK_TIME_END(a) QueryPerformanceCounter((LARGE_INTEGER*)&end); a = (float)((float)(end - start) / (freq / 1000.0f))
float compute_time;


#define MATDIM 1024
double *pMatA, *pMatB, *pMatC;
void MultiplySquareMatrices_1(double *pDestMatrix, double *pLeftMatrix, double *pRightMatrix, int MatSize);
void MultiplySquareMatrices_2(double *pDestMatrix, double *pLeftMatrix, double *pRightMatrix, int MatSize);
void MultiplySquareMatrices_3(double *pDestMatrix, double *pLeftMatrix, double *pRightMatrix, int MatSize);
void MultiplySquareMatrices_4(double *pDestMatrix, double *pLeftMatrix, double *pRightMatrix, int MatSize);

void init_MatMat(void);

void main(void)
{
	init_MatMat();
	CHECK_TIME_START;
	MultiplySquareMatrices_1(pMatC, pMatA, pMatB, MATDIM);
	//Sleep(500);
	CHECK_TIME_END(compute_time);
	printf("MultiplySquareMatrices_1 : %f ms\n", compute_time);

	CHECK_TIME_START;
	MultiplySquareMatrices_2(pMatC, pMatA, pMatB, MATDIM);
	//Sleep(500);
	CHECK_TIME_END(compute_time);
	printf("MultiplySquareMatrices_2 = %f ms\n", compute_time);

	CHECK_TIME_START;
	MultiplySquareMatrices_3(pMatC, pMatA, pMatB, MATDIM);
	//Sleep(500);
	CHECK_TIME_END(compute_time);
	printf("MultiplySquareMatrices_3 = %f ms\n", compute_time);

	CHECK_TIME_START;
	MultiplySquareMatrices_4(pMatC, pMatA, pMatB, MATDIM);
	//Sleep(500);
	CHECK_TIME_END(compute_time);
	printf("MultiplySquareMatrices_4 = %f ms\n", compute_time);
}

void MultiplySquareMatrices_1(double *pDestMatrix, double *pLeftMatrix ,double *pRightMatrix, int MatSize)
{
	for (int i = 0; i < MatSize; i++) {
		for (int j = 0; j < MatSize; j++) {
			pDestMatrix[i * MatSize + j] = 0;
			for (int k = 0; k < MatSize; k++) {
				pDestMatrix[i * MatSize + j] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + j];
			}
		}
	}
}

void MultiplySquareMatrices_2(double *pDestMatrix, double *pLeftMatrix, double *pRightMatrix, int MatSize)
{
	for (int k = 0; k < MatSize; k++) {
		for (int i = 0; i < MatSize; i++) {
			for (int j = 0; j < MatSize; j++) {
				pDestMatrix[i * MatSize + j] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + j];
			}
		}
	}
}

void MultiplySquareMatrices_3(double *pDestMatrix, double *pLeftMatrix, double *pRightMatrix, int MatSize)
{
	for (int k = 0; k < MatSize; k++) {
		for (int i = 0; i < MatSize; i++) {
			pDestMatrix[i * MatSize + 0] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 0];
			pDestMatrix[i * MatSize + 1] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 1];
			pDestMatrix[i * MatSize + 2] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 2];
			pDestMatrix[i * MatSize + 3] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 3];
			pDestMatrix[i * MatSize + 4] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 4];
			pDestMatrix[i * MatSize + 5] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 5];
			pDestMatrix[i * MatSize + 6] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 6];
			pDestMatrix[i * MatSize + 7] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 7];
			pDestMatrix[i * MatSize + 8] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 8];
			pDestMatrix[i * MatSize + 9] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + 9];
		}
	}
}

void MultiplySquareMatrices_4(double *pDestMatrix, double *pLeftMatrix, double *pRightMatrix, int MatSize)
{
	for (int k = 0; k < MatSize; k++) {
		for (int i = 0; i < MatSize; i++) {
			for (int j = 0; j < MatSize; j +=5 ) {
				pDestMatrix[i * MatSize + j + 0] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + j + 0];
				pDestMatrix[i * MatSize + j + 1] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + j + 1];
				pDestMatrix[i * MatSize + j + 2] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + j + 2];
				pDestMatrix[i * MatSize + j + 3] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + j + 3];
				pDestMatrix[i * MatSize + j + 4] += pLeftMatrix[i * MatSize + k] * pRightMatrix[k * MatSize + j + 4];
			}
		}
	}
}

void init_MatMat(void)
{
	double *ptr;
	pMatA = (double *)malloc(sizeof(double)*MATDIM*MATDIM);
	pMatB = (double *)malloc(sizeof(double)*MATDIM*MATDIM);
	pMatC = (double *)malloc(sizeof(double)*MATDIM*MATDIM);
	srand((unsigned)time(NULL));
	ptr = pMatA;
	for (int i = 0; i < MATDIM*MATDIM; i++)
		*ptr++ = (double)rand() / ((double)RAND_MAX);
	ptr = pMatB;
	for (int i = 0; i < MATDIM*MATDIM; i++)
		*ptr++ = (double)rand() / ((double)RAND_MAX);
}
