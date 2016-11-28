#include <stdio.h>

int MaxSubsequenceSum(int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;
    MaxSum = 0;
    for (i = 0; i < N; i++)
     {
        for (j = i; j < N; j++)
          {
            ThisSum = 0;
            for (k = i; k <= j; k++)
               {
                ThisSum += A[k];
               }
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
          }
     }
    return MaxSum;
}

int main(int argc, char* argv[])
{
    int a[] = {-2, 11, -4, 13, -5, -2};
    int b[] = {4, -3, 5, -2, -1, 2, 6, -2};

    printf("%d\n",MaxSubsequenceSum(a, 6));
    printf("%d\n",MaxSubsequenceSum(b, 8));
}
