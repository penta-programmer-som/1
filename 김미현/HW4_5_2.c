#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number(int n)
{
	if (n == 1) {
		printf("%d ", n);
		return n;
	}

	if (n % 2 == 0) {
		printf("%d ", n);
		n /= 2;
		return get_cycle_number(n) + 1;
	}
	else {
		printf("%d ", n);
		n = n * 3 + 1;
		return get_cycle_number(n) + 1;
	}
}

int main(void)
{
	int num;

	scanf("%d", &num);
	printf("%d", get_cycle_number(num));

	return 0;
}