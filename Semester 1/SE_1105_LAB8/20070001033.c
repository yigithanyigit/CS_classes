#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 4
typedef int matrix[ARRAY_SIZE][ARRAY_SIZE];

void fillMatrix(matrix m)
{
	for (int y = 0; y < ARRAY_SIZE; y++)
	{
		for (int x = 0; x < ARRAY_SIZE; x++)
		{
			printf("please type %d x %d th element\n", y + 1, x + 1);
			scanf(" %d", &m[y][x]);
		}
	}
}

void printMatrix(matrix m)
{
	for (int y = 0; y < ARRAY_SIZE; y++)
	{
		for (int x = 0; x < ARRAY_SIZE; x++)
		{
			printf("%d ", m[y][x]);
		}
		printf("\n");
	}
}

/*
 * operation = 'a'  ->  matrix addition
 * operation = 's'  ->  matrix substraction
 * operation = 'h'  *>  hadamard product
 */
void matrixOperation(matrix s, matrix a, matrix b, char operation)
{
	if (operation == 'a')
	{
		for (int y = 0; y < ARRAY_SIZE; y++)
		{
			for (int x = 0; x < ARRAY_SIZE; x++)
			{
				s[y][x] = a[y][x] + b[y][x];
			}
		}
	}
	else if (operation == 's')
	{
		for (int y = 0; y < ARRAY_SIZE; y++)
		{
			for (int x = 0; x < ARRAY_SIZE; x++)
			{
				s[y][x] = a[y][x] - b[y][x];
			}
		}
	}
	else if (operation == 'h')
	{
		for (int y = 0; y < ARRAY_SIZE; y++)
		{
			for (int x = 0; x < ARRAY_SIZE; x++)
			{
				s[y][x] = a[y][x] * b[y][x];
			}
		}
	}
}

void matrixMultiplication(matrix s, matrix a, matrix b)
{
	// substrac columns
	for (int x = 0; x < ARRAY_SIZE; x++)
	{
		for (int y = 0; y < ARRAY_SIZE; y++)
		{
			//b[y][x]

			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				//a[i][j]
				int val = 0;
				for (int j = 0; j < ARRAY_SIZE; j++)
				{
					val += b[y][x] * a[i][j];
				}
				s[x][i] = val;
			}
		}
	}
}

int main()
{
	matrix a, b, add, sub, hmd, mul;
	printf("Fill the first matrix:\n");
	fillMatrix(a);
	printf("\nFill the second matrix:\n");
	fillMatrix(b);
	matrixOperation(add, a, b, 'a');
	matrixOperation(sub, a, b, 's');
	matrixOperation(hmd, a, b, 'h');
	matrixMultiplication(mul, a, b);
	printf("\nMatrix Addition:\n");
	printMatrix(add);
	printf("\nMatrix Substraction:\n");
	printMatrix(sub);
	printf("\nHamadard product:\n");
	printMatrix(hmd);
	printf("\nMatrix multiplication:\n");
	printMatrix(mul);
	return 0;
}
