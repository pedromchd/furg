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
#include <math.h>

bool* sieveEratosthenes(int n) {
    bool* sieve = (bool*)malloc((n + 1) * sizeof(bool));
    if (sieve == NULL) {
        printf("Falha ao alocar memória\n");
        exit(1);
    }

    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i <= n; i++) {
        sieve[i] = true;
    }

    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (sieve[i] == true) {
            for (int j = pow(i, 2); j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }

    return sieve;
}

int main(void) {
    int n;

    printf("Exibir primos de 2 até... ");
    scanf("%d", &n);

    bool* sieve = sieveEratosthenes(n);
    for (int i = 0; i <= n; i++) {
        if (sieve[i] == true) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(sieve);
    return 0;
}
