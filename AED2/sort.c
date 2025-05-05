/*
ORDENA(A)
    for i = 1 to A.length
        min = A[i]
        minIndex = i
        for j = i to A.length
            num = A[j]
            if num < min
                min = num
                minIndex = j
        swap(A[i], A[minIndex])

SELECTION-SORT(A)
    n <- length[A];                     C_1 = 1
    for j <- 1 to n - 1 do              C_2 = ((n - 1) - 1) + 1 + 1 = n
        smallest <- j;                  C_3 = n - 1
        for i <- j + 1 to n do          C_4 = (n - (j + 1)) + 1 + 1 = n - j + 1  j = 1;      n - 1 + 1 = n
            if A[i] < A[smallest] then  C_5 = n - j = (n^2 - n)/2                j = 2;      n - 2 + 1 = n - 1
                smallest <- i;          C_6 = T6 = 0 (BC) / (n^2 - n)/2 (WC)     j = 3;      n - 3 + 1 = n - 2
            enf if;                     C_7 = (n^2 - n)/2                       ...
        enf for;                        C_8 = n - 1                              j = n - 1   n - (n - 1) + 1 = 2
        tmp <- A[j];                    C_9 = n - 1                              somatorio(j = 1, n - 1, n - j + 1)
        A[j] <- A[smallest];            C10 = n - 1                              => (n + 2)(n - 1)/2 = (n^2 + n - 2)/2
        A[smallest] = tmp;              C11 = n - 1
    end for;                            C12 = 1
    end procedure                       C13 = 1
*/

#include "stdio.h"
#include "stdlib.h"

void ordena(int* nums, int numsSize);

int main(void)
{
    int numsSize;

    printf("numsSize: ");
    scanf("%d", &numsSize);

    int* nums = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        printf("Número: ");
        scanf("%d", nums + i);
    }

    for (int i = 0; i < numsSize; i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("\n");
    
    ordena(nums, numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("\n");

    return 0;
}

void ordena(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        int minNum = nums[i];
        int minIdx = i;
        for (int j = i; j < numsSize; j++)
        {
            int num = nums[j];
            if (num < minNum)
            {
                minNum = num;
                minIdx = j;
            }
        }
        int aux = nums[i];
        nums[i] = nums[minIdx];
        nums[minIdx] = aux;
    }
}
