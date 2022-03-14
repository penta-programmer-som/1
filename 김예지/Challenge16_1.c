#define _CRT_SECURE_NO_WARNINGS 
#define ROW_SIZE 3
#define COL_SIZE 10
#include <stdio.h>

void printSeats(int s[3][10], int row_size, int col_size) // 좌석 보여주기 
{
	int i, j;

	printf("--------------------------------------------\n");
	printf("\t 1 2 3 4 5 6 7 8 9 10\n");
	printf("--------------------------------------------\n");

	for (i = 0; i < row_size; i++) {
		printf("%d\t", i + 1);
		for (j = 0; j < col_size; j++) {
			printf("%2d", s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int proessResvation(int s[ROW_SIZE][COL_SIZE], int r, int c)
{
	if (s[r - 1][c - 1] == 1) {
		printf("이미 예약된 자리입니다.\n");
		return 1;
	}
	else {
		s[r - 1][c - 1] = 1;
		printf("예약되었습니다.\n");
	}
	return 0;
}

int main(void)
{
	int seats[ROW_SIZE][COL_SIZE] = { 0 };
	char choice;
	int r, c;

	do
	{
		printf("좌석을 예약하시겠습니까? (y/n) ");
		scanf("%c", &choice);

		if (choice == 'n')
			break;

		printSeats(seats,ROW_SIZE,COL_SIZE);

		printf("\n몇번째 좌석을 예약하시겠습니까?(열 행)의 형태로 입력 : ");
		scanf("%d %d", &r, &c);

		if ((proessResvation(seats, r, c) == 1)) {
			while (getchar() != '\n');
			continue;
		}
		printSeats(seats, ROW_SIZE, COL_SIZE);

		while (getchar() != '\n');
	} while (choice == 'y');
}
