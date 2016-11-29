#include <stdio.h>

int MaxSubsequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, j;

	ThisSum = MaxSum = 0;
	for (j = 0; j < N; j++)
	{
		ThisSum += A[j];

		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}

int main(int argc, char* argv[])
{
	int a[] = {-2, 11, -4, 13, -5, -2};
	int b[] = {4, -3, 5, -2, -1, 2, 6, -2};
	int c[] = {4, -3, 5, -2, -4, -1, 2, 6, -2, 10, -1};

	printf("%d\n", MaxSubsequenceSum(a, 6));
	printf("%d\n", MaxSubsequenceSum(b, 8));
	printf("%d\n", MaxSubsequenceSum(c, 11));
}