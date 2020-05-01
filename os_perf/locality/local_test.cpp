/*****************************************
*   Copyright (C) 2020 All rights reserved.
*   File: local_test.cpp
*   Auth: LiuLang
*   Mail: datuhao@foxmail.com
*   Date: 2020-05-01 18:15
*   Desc: 
*****************************************/
#include "../utils/time_utls.h"
#include <stdio.h>



#define M 10
#define N 10
int arr[10][10] = {
	{1, 2, 3, 4, 5 , 6, 7, 8, 9, 10},
	{11, 12, 13, 14, 15 ,16, 17, 18, 19, 20},
	{21, 22, 23, 24, 25 , 26, 27, 28, 29, 30},
	{31, 32, 33, 34, 35 , 36, 37, 38, 39, 40},
	{41, 42, 43, 44, 45 , 46, 47, 48, 49, 50},
	{51, 52, 53, 54, 55 , 56, 57, 58, 59, 60},
	{61, 62, 63, 64, 65 , 66, 67, 68, 69, 70},
	{71, 72, 73, 74, 75 , 76, 77, 78, 79, 80},
	{81, 82, 83, 84, 85 , 86, 87, 88, 89, 90},
	{91, 92, 93, 94, 95 , 96, 97, 98, 99, 100},
};

int sumarrayrows(int a[M][N])
{
	int sum = 0;
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			sum += a[i][j];
		}
	}
	return sum;
}

int sumarraycols(int a[M][N])
{
	int sum = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			sum += a[j][i];
		}
	}
	return sum;
}

int main(int argc, char *argv[])
{
	uint64_t sum = 0;
	uint64_t tm1 = dsn_now_us();
	for(int i=0; i<1000; i++)
		sum = sumarrayrows(arr);	
	uint64_t tm2 = dsn_now_us();
	for(int i=0; i<1000; i++)
		sum += sumarraycols(arr);	
	uint64_t tm3 = dsn_now_us();

	printf("sum:%lu\n", sum);	
	printf("rows times:%lu(us), cols times:%lu(us)\n", tm2-tm1, tm3-tm2);

	return 0;
}


