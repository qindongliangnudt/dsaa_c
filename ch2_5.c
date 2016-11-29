#include <stdio.h>

int BinarySearch(const int A[], int x, int N)
{
	int Low, Mid, High;

	Low = 0; High = N - 1;
	while (Low <= High)
	{
		Mid = (Low + High) / 2;
		if (A[Mid] < x)
			Low = Mid + 1;
		else if (A[Mid] > x)
			High = Mid - 1;
		else
			return Mid+1;
	}
	return -1;
}

int main(int argc, char* argv[])
{
	int a[] = {3, 11, 14, 15, 35, 47};
	int b[] = {4, 4, 5, 12, 21, 32, 36, 42};
	int c[] = {4, 13, 15, 22, 24, 31, 32, 36, 42, 50, 51};

	printf("%d\n", BinarySearch(a, 35, 6));
	printf("%d\n", BinarySearch(b, 8, 8));
	printf("%d\n", BinarySearch(c, 13, 11));
}