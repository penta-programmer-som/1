#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n);
int main(void)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    get_cycle_number(num);
}

int get_cycle_number(int n)
{
    int count = 0;

    printf("%d ", n);

    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = (n * 3) + 1;

        printf("%d ", n);
        count++;
    }

    printf("\n사이클의 길이는 %d\n", count + 1);
}