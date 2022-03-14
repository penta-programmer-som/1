#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else return gcd(b, a % b);
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
	printf("%d와 %d의 최대공약수는 %d.", a, b, gcd(a, b));
}