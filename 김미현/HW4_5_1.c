#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number(int n)
{
	int total = 1;

	printf("%d ", n);
	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;

		printf("%d ", n);
		total++;
	}
	printf("\n");

	return total;
}

int main(void)
{
	int num, total = 0;

	scanf("%d", &num);
	printf("%d", get_cycle_number(num));

	return 0;
}