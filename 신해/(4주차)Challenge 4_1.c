#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int gcd(int a, int b)
{
	int r;
	do {
		r = a % b;
		a = b;
		b = r;

	} while (r != 0);

	return a;
}
int main(void)
{
	int a, b, c;
	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);
	if (a < b)
	{
		c = a;
		a = b;
		b = c;
	}
	printf("%d�� %d�� �ִ������� %d.", a, b, gcd(a, b));
}