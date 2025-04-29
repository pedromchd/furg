#include "stdio.h"
#include "stdbool.h"

bool isPrime(int number);

int main(void)
{
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    char* res = isPrime(num) ? "%d é primo!\n" : "%d não é primo...\n";

    printf(res, num);

    return 0;
}

bool isPrime(int number)
{
    if (number < 2)
    {
        return false;
    }

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}
