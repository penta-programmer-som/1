#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>

char askReservation()
{
	char ch;
	printf("좌석을 예약하시겠습니까?(y/n) ");
	scanf("%c", &ch);
	return ch;
}

void printSeats(int s[][SIZE], int size)
{
	int i, j;
	printf("_______________________________________\n \t");
	for (i = 0; i < SIZE; i++)
		printf("%2d ", i + 1);
	printf("\n_______________________________________\n");

	for (i = 0; i < size; i++) {
		printf("%d\t", i + 1);
		for (j = 0; j < SIZE; j++) {
			printf("%2d ", s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void processReservation(int s[][SIZE], int size, int x, int y)
{
	if (s[x - 1][y - 1] == 0) {
		s[x - 1][y - 1] = 1;
		printf("예약되었습니다.");
		printSeats(s, size);
	}
	else
		printf("이미 예약된 자리 입니다.\n");
}

int main(void)
{
	int cX, cY;
	int seats[3][SIZE] = { 0 };
	while (askReservation() == 'y') {
		printSeats(seats, 3);
		printf("몇번째 좌석을 예약하시겠습니까? (열 행)의 형태로 입력: ");
		scanf("%d %d", &cX, &cY);
		processReservation(seats, 3, cX, cY);
		while (getchar() != '\n');
	}

	return 0;
}