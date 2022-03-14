#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number(int n)
{
	printf("%d ", n);

	if (n == 1)
		return 1;

	if (n % 2 == 0)
		return get_cycle_number(n / 2) + 1;
	return get_cycle_number(n * 3 + 1) + 1;
}

int main(void)
{
	int n;

	printf("정수를 입력하세요 : ");
	scanf("%d", &n);

	printf("\n사이클 길이는 %d\n", get_cycle_number(n));
}
