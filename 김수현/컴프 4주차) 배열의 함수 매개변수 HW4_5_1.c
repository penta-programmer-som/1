#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n)
{
	int count = 0;
	while (n != 1) {
		count++;
		if (n % 2 == 0) {
			printf("%d ", n);
			n = n / 2;
		}
		else {
			printf("%d ", n);
			n = n * 3 + 1;
		}
	}
	printf("%d\n", n);
	count++;
	return count;
}
int main(void)
{
	int number = 22;
	printf("%d", get_cycle_number(number));
}