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
