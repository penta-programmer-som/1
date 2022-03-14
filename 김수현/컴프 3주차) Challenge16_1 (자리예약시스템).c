#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
void print(int s[][10])
{
	int i, j;
	printf("\n--------------------------------------\n");
	printf("\t");
	for (j = 0; j < 10; j++)
		printf("%2d ", j + 1);
	printf("\n");
	printf("--------------------------------------\n");
	for (i = 0; i < 3; i++) {
		printf("%d\t", i + 1);
		for (j = 0; j < 10; j++)
			printf("%2d ", s[i][j]);
		printf("\n");
	}
	printf("--------------------------------------\n");

}
int main(void)
{
	char key;
	int display[3][10] = { 0 };
	int r;
	int c;
	int count = 0;
	
	do
	{
		printf("좌석을 예약하시겠습니까?(y/n) ");
		scanf("%c", &key);
		if (key == 'n')//이거 없이는 왜 안되는 걸까?
			break;
		while (getchar() != '\n');
		
		print(display);

		printf("몇번째 좌석을 예약하시겠습니까? <열 행>의 형태로 입력: ");
		scanf("%d %d", &r, &c);
		while (getchar() != '\n');

		
		if (display[r-1][c-1] == 1) {
			printf("이미 예약된 자리입니다.\n");
			continue;
		}

		display[r-1][c-1] = 1;
		printf("예약되었습니다.\n");
		print(display);
		count++;

	} while (key == 'y');
	
}