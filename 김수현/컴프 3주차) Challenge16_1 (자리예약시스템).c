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
		printf("�¼��� �����Ͻðڽ��ϱ�?(y/n) ");
		scanf("%c", &key);
		if (key == 'n')//�̰� ���̴� �� �ȵǴ� �ɱ�?
			break;
		while (getchar() != '\n');
		
		print(display);

		printf("���° �¼��� �����Ͻðڽ��ϱ�? <�� ��>�� ���·� �Է�: ");
		scanf("%d %d", &r, &c);
		while (getchar() != '\n');

		
		if (display[r-1][c-1] == 1) {
			printf("�̹� ����� �ڸ��Դϴ�.\n");
			continue;
		}

		display[r-1][c-1] = 1;
		printf("����Ǿ����ϴ�.\n");
		print(display);
		count++;

	} while (key == 'y');
	
}