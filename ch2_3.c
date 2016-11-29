#include <stdio.h>

static int Max2(int a, int b)
{
	return a >= b ? a : b;
}

static int Max3(int a, int b, int c)
{
	return (Max2(Max2(a, b), c));
}

static int MaxSubSum(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBrderSum, RightBorderSum;
	int Center, i;

	/* base case */
	if (Left == Right)
	{
		if (A[Left] > 0)
			return A[Left];
		else
			return 0;
	}

	/* divide */
	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center + 1, Right);

	/* the max subsequence sum including the right-most of left sub */
	MaxLeftBorderSum = 0;
	LeftBrderSum = 0;
	for (i = Center; i >= Left; i--)
	{
		LeftBrderSum += A[i];
		if (LeftBrderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBrderSum;
	}

	/* the max subsequence sum including the left-most of right sub */
	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = Center + 1; i <= Right; i++)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	/* compare three above */
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);

}

int MaxSubsequenceSum(const int A[], int N)
{
	return MaxSubSum(A, 0, N-1);
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