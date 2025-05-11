/*
algorithm Sieve of Eratosthenes is
    input: an integer n > 1.
    output: all prime numbers from 2 through n.

    let A be an array of Boolean values, indexed by integers 2 to n,
    initially all set to true.

    for i = 2, 3, 4, ..., not exceeding √n do
        if A[i] is true
            for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
                set A[j] := false

    return all i such that A[i] is true.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* crivoDeEratostenes(int n) {
    bool ehPrimo[n + 1];

    ehPrimo[0] = false;
    ehPrimo[1] = false;
    for (int i = 2; i <= n; i++) {
        ehPrimo[i] = true;
    }

    for (int p = 2; p * p <= n; p++) {
        if (ehPrimo[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                ehPrimo[i] = false;
            }
        }
    }

    int* primos = (int*)calloc((n + 1), sizeof(int));
    if (primos == NULL) {
        printf("Falha ao alocar memória\n");
        exit(1);
    }

    int primosIndex = 0;
    for (int i = 2; i <= n; i++) {
        if (ehPrimo[i] == true) {
            primos[primosIndex] = i;
            primosIndex++;
        }
    }

    return primos;
}

int main(void) {
    int limite = 30;

    int* primos = crivoDeEratostenes(limite);

    printf("Primos até %d: ", limite);
    int primosIndex = 0;
    while(primos[primosIndex] != 0) {
        printf("%d, ", primos[primosIndex]);
        primosIndex++;
    }

    free(primos);
    return 0;
}
