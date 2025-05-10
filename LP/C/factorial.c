#include "stdio.h"

int factorial(int number);

int main(void)
{
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    int fat = factorial(num);

    printf("%d\n", fat);

    return 0;
}

int factorial(int number)
{
    if (number < 2) {
        return 1;
    }

    int res = number;

    for (int i = 2; i < number; i++)
    {
        res *= i;
    }

    return res;
}
