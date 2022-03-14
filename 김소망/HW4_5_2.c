#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n);
int main(void)
{
    int num;

    printf("Enter a number ");
    scanf("%d", &num);

    printf("\n사이클의 길이는 : %d\n", get_cycle_number(num));
}

int get_cycle_number(int n)
{

    printf("%d ", n);

    if (n == 1)
        return 1;

    if (n % 2 == 0)
        n = n / 2;
    else
        n = n * 3 + 1;

    return get_cycle_number(n) + 1;
}