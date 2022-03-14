#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define X_VALUE 5 // 2차원 배열 행의 수 
#define Y_VALUE 5 // 2차원 배열 열의 수 

void readBombInfo(char grid[][Y_VALUE + 1])
{
	int i;
	
	// grid 및 지뢰 정보 입력
	printf("Input Grid\n");

	for (i = 0; i < X_VALUE; i++)
		scanf("%s", grid[i]);
}

void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;

	for(i=0; i<X_VALUE; i++)
		for(j=0; j<Y_VALUE; j++)
			if (grid[i][j] == '*') {
				// 지뢰의 개수를 세어 numOfBombs 에 넣는 코드 

				if (i - 1 >= 0) {
					numOfBombs[i - 1][j]++;
					if (j - 1 >= 0)
						numOfBombs[i - 1][j - 1]++;
					if (j + 1 < Y_VALUE)
						numOfBombs[i - 1][j + 1]++;
				}

	
				if (i + 1 < X_VALUE) {
					numOfBombs[i + 1][j]++;
					if (j - 1 >= 0)
						numOfBombs[i + 1][j - 1]++;
					if (j + 1 < Y_VALUE)
						numOfBombs[i + 1][j + 1]++;
				}

	
				if (j - 1 >= 0)
					numOfBombs[i][j - 1]++;
	
				if (j + 1 < Y_VALUE)
					numOfBombs[i][j + 1]++;
			}
}

void display_numOfBombs(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;

	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		printf("\n");
	}
}

int main(void)
{
	char grid[X_VALUE][Y_VALUE + 1];
	int numOfBombs[X_VALUE][Y_VALUE] = { 0 };

	readBombInfo(grid);
	countBomb(grid, numOfBombs);
	printf("\n");
	display_numOfBombs(grid, numOfBombs);
}
