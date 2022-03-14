//왜 오류가 ???
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
void printMatrix(int a[][3], int size)
{
	int i;
	int j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < 3; j++)
			printf("%2d ", a[i][j]);
		printf("\n");
	}
}
void readMatrix(int a[][3], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
}
void readMatrix2(int a[][2], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < 2; j++)
			scanf("%d", &a[i][j]);
}
int main(void)
{
	int m, n, p;
	int X[4][2], Y[2][3], Z[4][3];

	printf("(4 x 2) 행렬 X 입력:\n");
	readMatrix2(X, 4);
	printf("(2 x 3) 행렬 Y 입력:\n");
	readMatrix(Y, 2);

	for (m = 0; m < 4; m++)
		for (p = 0; p < 3; p++)
			for (n = 0; n < 2; n++)
				Z[m][p] += X[m][n] * Y[n][p];

	printf("행렬곱:\n"); 
	printMatrix(Z, 4);
	printf("\n");
}
