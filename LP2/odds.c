#include "stdio.h"

void writeOdds(int number);

int main(void)
{
    int num;

    printf("Digite o número de ímpares: ");
    scanf("%d", &num);

    writeOdds(num);

    return 0;
}

void writeOdds(int number)
{
    for (int i = 1; i <= number; i++)
    {
        printf("%d ", 2 * i + 1);
    }

    printf("\n");
}
