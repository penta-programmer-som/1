#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	int cycle = 0;

	scanf("%d", &n);

	printf("\n%d", get_cycle_number(n));
}
int get_cycle_number(int n)
{
	printf("%2d ", n);

	if (n == 1)
		return 1;
	else if (n % 2 == 0)
		return get_cycle_number(n / 2) + 1;
	else
		return get_cycle_number(n * 3 + 1) + 1;
}