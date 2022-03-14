#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int gcd(int x, int y)
{
	int r;		
	do {
		r = x % y;
		x = y;
		y = r;

	} while (r != 0);

	return x;//y값 (x로 이동한 것)
}
int main(void)
{
	int a, b, big, small;
	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);
	if (a < b)
	{
		big = b;
		small = a;
	}
	else
	{
		big = a;
		small = b;
	}
	printf("%d 와 %d의 최대공약수는 %d\n", a, b, gcd(big, small));
}