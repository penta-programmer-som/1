#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printMatrix(int a[][3], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++)
			printf("%2d ", a[i][j]);
		printf("\n");
	}
	return;
}

void readMatrix(int a[][2], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &a[i][j]);
	return;
}

void readMatrix2(int a[][3], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	return;
}

void matrixMultiplication(int a[][2], int b[][3], int c[][3], int size)
{
	int i, j, k, num;
	for (i = 0; i < size; i++) {
		for (j = 0; j < 3; j++) {
			num = 0;
			for (k = 0; k < 2; k++) {
				num += a[i][k] * b[k][j];
			}
			c[i][j] = num;
		}
	}
	return;
}

int main(void)
{
	int X[4][2], Y[2][3], Z[4][3];
	printf("(4 x 2) 행렬 X 입력 : \n");
	readMatrix(X, 4);
	printf("(2 x 3) 행렬 Y 입력 : \n");
	readMatrix2(Y, 2);
	matrixMultiplication(X, Y, Z, 4);
	printf("행렬곱 : \n");
	printMatrix(Z, 4);
	printf("\n");
	return 0;
}