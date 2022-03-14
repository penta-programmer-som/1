#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number(int n)
{
	int len = 1;
	printf("%d ", n);

	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;

		len++;
		printf(" %d", n);
	}
	printf("\n");
	return len;
}

int main(void)
{
	int n;

	scanf("%d", &n);

	printf("사이클 길이는 %d\n", get_cycle_number(n));
}
