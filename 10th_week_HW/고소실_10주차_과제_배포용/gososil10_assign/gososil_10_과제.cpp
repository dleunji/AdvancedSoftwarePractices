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
float compute_time1, compute_time2;


#define MATDIM 1024
#define HW1_N 100000
float *hw1_x, hw1_E, hw1_var1, hw1_var2;
float hw2_a, hw2_b, hw2_c, hw2_naive_ans[2], hw2_pre_ans[2];

/* hw1 */
void init_hw1(int fixed);
void hw1_calc_e();
void hw1_calc_var1();
void hw1_calc_var2();
/* hw2 */
void hw2_naive();
void hw2_safe();
float hw2_verify(float x);
/* hw3 */
void for1();
void for2();
void for3(const char* string);
void for4(const char* string);
void elseif1(float condition);
void elseif2(float condition);
void loop1();
void loop2();
void loop3();
void loop4();




void main(void)
{
	srand((unsigned)time(NULL));

	/* hw1 */
	puts("====== hw1 ======");
	init_hw1(1);
	hw1_calc_e();
	CHECK_TIME_START;
	hw1_calc_var1();
	CHECK_TIME_END(compute_time);
	compute_time1 = compute_time;
	printf("hw1_calc_var1 = %f ms\n", compute_time);
	printf("hw1_calc_var1 value = %.15f\n", hw1_var1);


	CHECK_TIME_START;
	hw1_calc_var2();
	CHECK_TIME_END(compute_time);
	compute_time2 = compute_time;
	printf("hw1_calc_var2 = %f ms\n", compute_time);
	printf("hw1_calc_var2 value = %.15f\n", hw1_var2);
	puts("");
	
	/* hw2 */
	puts("====== hw2 ======");
	printf("a, b, c : ");
	scanf("%f %f %f", &hw2_a, &hw2_b, &hw2_c);
	hw2_naive();
	printf("naive result    : %.15f, %.15f\n", hw2_naive_ans[0], hw2_naive_ans[1]);
	hw2_safe();
	printf("advanced result : %.15f, %.15f\n", hw2_pre_ans[0], hw2_pre_ans[1]);
	puts("");
	printf("Verifying naive ans    : %.15f, %.15f\n", hw2_verify(hw2_naive_ans[0]), hw2_verify(hw2_naive_ans[1]));
	printf("Verifying advanced ans : %.15f, %.15f\n", hw2_verify(hw2_pre_ans[0]), hw2_verify(hw2_pre_ans[1]));
	puts("");

	/* hw3 */
	puts("====== hw3 ======");
	/////////////////////////////////////////////////////////////////////
	CHECK_TIME_START;
	for1();
	CHECK_TIME_END(compute_time);
	printf("The runtime of increasing for-loop is %.15f\n", compute_time);
	puts("");

	CHECK_TIME_START;
	for2();
	CHECK_TIME_END(compute_time);
	printf("The runtime of decreasing for-loop is %.15f\n", compute_time);
	puts("");
	/////////////////////////////////////////////////////////////////////
	const char* string = "ADFSDFGGGTFDSSSSSSGGBKKKKSKKSKSKSKSKEKEKEKEKEKEALLAL";
	CHECK_TIME_START;
	for3(string);
	CHECK_TIME_END(compute_time);
	printf("The runtime of calling strlen() several times is %.15f\n", compute_time);
	puts("");

	CHECK_TIME_START;
	for4(string);
	CHECK_TIME_END(compute_time);
	printf("The runtime of calling strlen() once is %.15f\n", compute_time);
	puts("");
	/////////////////////////////////////////////////////////////////////
	float condition = 8.0;
	CHECK_TIME_START;
	elseif1(condition);
	CHECK_TIME_END(compute_time);
	printf("The runtime of non-breakdown if statement is %.15f\n", compute_time);
	puts("");

	condition = 8.0;
	CHECK_TIME_START;
	elseif2(condition);
	CHECK_TIME_END(compute_time);
	printf("The runtime of breakdown if statement is %.15f\n", compute_time);
	puts("");
	/////////////////////////////////////////////////////////////////////
	CHECK_TIME_START;
	loop1();
	CHECK_TIME_END(compute_time);
	printf("The runtime of loop1 is              %.15f\n", compute_time);
	puts("");

	CHECK_TIME_START;
	loop2();
	CHECK_TIME_END(compute_time);
	printf("The runtime of loop2 with jamming is %.15f\n", compute_time);
	puts("");
	/////////////////////////////////////////////////////////////////////
	CHECK_TIME_START;
	loop3();
	CHECK_TIME_END(compute_time);
	printf("the runtime of non-break loop is %.15f\n", compute_time);
	puts("");

	CHECK_TIME_START;
	loop4();
	CHECK_TIME_END(compute_time);
	printf("the runtime of break loop is   %.15f\n", compute_time);
	system("pause");




}

void init_hw1(int fixed)
{
	float *ptr;
	hw1_x = (float *)malloc(sizeof(float)*HW1_N);

	if (fixed)
	{
		float tmp = HW1_N;
		for (int i = 0; i < HW1_N; i++)
		{
			if (i & 1) {
				tmp -= 0.0001;
			}
			hw1_x[i] = tmp;
		}
	}
	else
	{
		srand((unsigned)time(NULL));
		ptr = hw1_x;
		for (int i = 0; i < HW1_N; i++)
			*ptr++ = ((float)rand() / (float)RAND_MAX) * 2;
	}
}
void hw1_calc_e()
{
	for (int i = 0; i < HW1_N; i++) {
		hw1_E += hw1_x[i];
	}
	hw1_E /= HW1_N;
}
void hw1_calc_var1()
{
	hw1_var1 = 0;
	for (int i = 0; i < HW1_N; i++) {
		hw1_var1 += pow(hw1_x[i] - hw1_E, 2);
	}
	hw1_var1 /= (HW1_N - 1);
}
void hw1_calc_var2()
{
	hw1_var2 = 0;
	double tmp = 0;
	for (int i = 0; i < HW1_N; i++) {
		tmp += pow(hw1_x[i], 2);
	}
	tmp = tmp * HW1_N - pow(HW1_N * hw1_E,2);//음수의 가능성 존재
	hw1_var2 = tmp / (HW1_N * (HW1_N - 1));
}


/* hw2 */
void hw2_naive()
{
	float det = pow(hw2_b, 2) - 4 * hw2_a * hw2_c;
	if (det >= 0.0) {
		hw2_naive_ans[0] = (-hw2_b + sqrt(pow(hw2_b, 2) - 4 * hw2_a * hw2_c)) / 2 * hw2_a;
		hw2_naive_ans[1] = (-hw2_b - sqrt(pow(hw2_b, 2) - 4 * hw2_a * hw2_c)) / 2 * hw2_a;
	}
}
void hw2_safe()
{	
	float det = pow(hw2_b, 2) - 4 * hw2_a * hw2_c;
	float tmp;
	if (det > 0.0) {
		if (hw2_b >= 0) {
			hw2_pre_ans[0] = (2 * hw2_c) / (-hw2_b - sqrt(det));
			//hw2_pre_ans[1] = (2 * hw2_c) / (-hw2_b + sqrt(det));
			tmp = 1 / hw2_pre_ans[0] + (sqrt(det) / hw2_c);
			hw2_pre_ans[1] = 1 / tmp;
		}
		else {
			hw2_pre_ans[0] = (2 * hw2_c) / (-hw2_b + sqrt(det));
			//hw2_pre_ans[1] = (2 * hw2_c) / (-hw2_b - sqrt(det));
			tmp = 1 / hw2_pre_ans[0] - (sqrt(det) / hw2_c);
			hw2_pre_ans[1] = 1 / tmp;
		}
	}
	else if (det == 0.0) {
		hw2_pre_ans[0] = (2 * hw2_c) / (-hw2_b + sqrt(det));
		hw2_pre_ans[1] = hw2_pre_ans[0];
	}
	else {

	}
}
float hw2_verify(float x)
{
	return hw2_a * x * x + hw2_b*x + hw2_c;
}


/* hw3 */
void for1() {
	float sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum += i;
	}
}
void for2() {
	float sum = 0;
	for (int i = 10000; i > 0; i--) {
		sum += i;
	}
}

void for3(const char* string) {
	float sum = 0;
	for (int i = 0; i < strlen(string); i++) {
		sum += i;
	}

}

void for4(const char* string) {
	float sum = 0;
	float count = strlen(string);
	for (int i = 0; i < count; i++) {
		sum += i;
	}
}
void elseif1(float condition) {
	if (condition == 1)
		printf("condition is 1\n");
	else if (condition == 2)
		printf("condition is 2\n");
	else if (condition == 3)
		printf("condition is 3\n");
	else if (condition == 4)
		printf("condition is 4\n");
	else if (condition == 5)
		printf("condition is 5\n");
	else if (condition == 6)
		printf("condition is 6\n");
	else if (condition == 7)
		printf("condition is 7\n");
	else if (condition == 8)
		printf("condition is 8\n");
	else if (condition == 9)
		printf("condition is 9\n");
}
void elseif2(float condition) {
	if (condition <= 4) {
		if (condition == 1)
			printf("condition is 1\n");
		else if (condition == 2)
			printf("condition is 2\n");
		else if (condition == 3)
			printf("condition is 3\n");
		else if (condition == 4)
			printf("condition is 4\n");
	}
	else {
		if (condition == 5)
		printf("condition is 5\n");
		else if (condition == 6)
		printf("condition is 6\n");
		else if (condition == 7)
		printf("condition is 7\n");
		else if (condition == 8)
		printf("condition is 8\n");
		else if (condition == 9)
		printf("condition is 9\n");
	}
}

void loop1() {
	float sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum += i;
	}

	for (int i = 0; i < 10000; i++) {
		sum -= i / 2;
	}
}
void loop2() {
	float sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum += i;
		sum -= i / 2;
	}
}

void loop3() {
	boolean found = false;
	for (int i = 0; i < 10000; i++) {
		if (i == 46597)
			found = true;
	}
}

void loop4() {
	boolean found = true;
	for (int i = 0; i < 10000; i++) {
		if (i == 46957) {
			found = true;
			break;
		}
	}
}