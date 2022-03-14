#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>

char askReservation()
{
	char ch;
	printf("�¼��� �����Ͻðڽ��ϱ�?(y/n) ");
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
		printf("����Ǿ����ϴ�.");
		printSeats(s, size);
	}
	else
		printf("�̹� ����� �ڸ� �Դϴ�.\n");
}

int main(void)
{
	int cX, cY;
	int seats[3][SIZE] = { 0 };
	while (askReservation() == 'y') {
		printSeats(seats, 3);
		printf("���° �¼��� �����Ͻðڽ��ϱ�? (�� ��)�� ���·� �Է�: ");
		scanf("%d %d", &cX, &cY);
		processReservation(seats, 3, cX, cY);
		while (getchar() != '\n');
	}

	return 0;
}