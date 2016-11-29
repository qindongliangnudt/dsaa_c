#include <stdio.h>

int MaxSubSequenceSum(int A[], int N)
{
    int MaxSum, ThisSum, i, j;
    MaxSum = 0;
    for (i = 0; i < N; i++) {
        ThisSum = 0;
        for (j = i; j < N; j++) {
            ThisSum += A[j];
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
    int c[] = {4, -3, 5, -2, -4, -1, 2, 6, -2, 10, -1};

    printf("%d\n", MaxSubSequenceSum(a, 6));
    printf("%d\n", MaxSubSequenceSum(b, 8));
    printf("%d\n", MaxSubSequenceSum(c, 11));
}
