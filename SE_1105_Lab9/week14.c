#include "stdio.h"
#include "stdbool.h"


double power(double m, int n)
{
	double result = 1;

	for (int i = 0; i < n; ++i)
	{
		result = result * m;
	}
	return result;
}

double q1(double x, int n)
{
	double sum = 0;
	double term = 1;

	for (int i = 0; i < n; ++i)
	{
		sum = sum + term;
		term = term / -x;
	}
	return sum;
}

#define N 20
double neighborAverage(double arr[N][N], int r, int c)
{
	double sum=0;
	int nc = 0;

	if (r > 0)
	{
		sum = sum + arr[r - 1][c];
		nc++;
	}
	if (c > 0)
	{
		sum = sum + arr[r][c-1];
		nc++;
	}

	if (r < N-1)
	{
		sum = sum + arr[r + 1][c];
		nc++;
	}

	if (c < N-1)
	{
		sum = sum + arr[r][c+1];
		nc++;
	}
	return sum / nc;
}


int q2(double arr[N][N])
{
	int count = 0;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (arr[r][c] > neighborAverage(arr, r, c))
			{
				count++;
			}
		}
	}
	return count;
}


void process(char *str)
{
	if (*str == NULL)// Empty string
		return;
	if (*str!= ' ') // First Character
	{
		*str = '.';
	}

	for( ;*(str+1) != NULL ; str++)
	{
		if (*str == ' ' && *(str + 1) != ' ' )
			*(str + 1) = '.';
	}

}

bool q1(char * w1, char *w2)
{
	while ( *w1!= NULL && *w2 != NULL)
	{
		if (*w1 == *w2 )
		{
			w2++;
		}
		w1++;
	}
	return *w2 == NULL;
}


double rowSum(double arr[N][N], int row)
{
	double sum = 0;

	for (int c = 0; c < N; ++c)
	{
		sum = sum + arr[row][c];
	}
	return sum;
}

int maxSumRow(double arr[N][N])
{
	double maxSum = rowSum(arr, 0);
	int maxSumIndex = 0;
	for (int i = 1; i < N; ++i)
	{
		int sum = rowSum(arr, i);

		if (sum > maxSum)
		{
			maxSum = sum;
			maxSumIndex = i;
		}
	}
	return maxSumIndex;
}


void main()
{
	char str[] = "This is an example v";
	process(str);

	printf(str);
	printf("\n");
}