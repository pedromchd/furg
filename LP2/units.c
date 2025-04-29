#include "stdio.h"

float fahreinheitToCelsius(float temperature);

int main(void)
{
    float temp;

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &temp);

    float celsius = fahreinheitToCelsius(temp);

    printf("%.1f°F -> %.1f°C\n", temp, celsius);

    return 0;
}

float fahreinheitToCelsius(float temperature)
{
    return (temperature - 32) * 5 / 9;
}
