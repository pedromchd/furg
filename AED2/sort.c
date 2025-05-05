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
    n <- length[A];                     C1
    for j <- 1 to n - 1 do              C2 * n
        smallest <- j;                  C3 * (n - 1)
        for i <- j + 1 to n do          C4 * (n - 1) * (n - 1 + 1)
            if A[i] < A[smallest] then  C5 * (n - 1) * n
                smallest <- i;          C6 * (n - 1) * n
            enf if;
        enf for;
        tmp <- A[j];                    C7 * (n - 1)
        A[j] <- A[smallest];            C8 * (n - 1)
        A[smallest] = tmp;              C9 * (n - 1)
    end for;
    end procedure
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
