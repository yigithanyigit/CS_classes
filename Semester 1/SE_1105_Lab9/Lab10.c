#include <stdio.h>

void printAddressOfVariable(int a)
{
	printf("%d\n", &a);
}

void printValueOfAddress(int *a)
{
	printf("%d\n", *a);
}

int add_v1(int a, int b)
{
	return a + b;
}

void add_v2(int *s, int a, int b)
{
	*s = a + b;
}

void add_v3(int *s, int *a, int *b)
{
	*s = *a + *b;
}

void swap(int *a, int *b)
{
	*b = *a + *b;
	*a = *b - *a;
	*b = *b - *a;
}

void labwork6(int * max, int *min, int *avg, int arr[], int size)
{
	*max = arr[0];
	*min = arr[0];
	*avg = arr[0];
	for (int i = 1; i < size; i++)
	{

		if (arr[i] > *max)
		{
			*max = arr[i];
		}
		if (arr[i] > *max)
		{
			*min = arr[i];
		}
		*avg += arr[i];
	}
	*avg /= size;
}

int main()
{
	printf("Testing printAddressOfVariable function ...\n");
	int a = 10;
	printf("The value of the variable is %d\n", a);
	printf("The address of the variable is ");
	printAddressOfVariable(a);
	printf("\n");

	printf("Testing printValueOfAddress function ...\n");
	int b = 20;
	int *c = &b;
	printf("The address of the variable is %d\n", c);
	printf("The value of the variable is ");
	printValueOfAddress(c);
	printf("\n");

	// TODO: Write test codes for all add functionsc

	printf("Testing Add V1 function ...\n");
	int d = 20, e = 20, s = 0;
	printf("The addresses of the variables are a: %d b: %d s:%d \n", d, e, s);
	printf("The result of the variable is ");
	s = add_v1(d, e);
	printValueOfAddress(&s);
	printf("\n");

	printf("Testing Add V2 function ...\n");
	e = 30;
	d = 40;
	s = 0;
	printf("The addresses of the variables are a: %d b: %d s:%d \n", d, e, s);
	printf("The result of the variable is ");
	add_v2(&s, d, e);
	printValueOfAddress(&s);
	printf("\n");

	printf("Testing Add V3 function ...\n");
	e = 15;
	d = 35;
	s = 0;
	printf("The addresses of the variables are a: %d b: %d s:%d \n", d, e, s);
	printf("The result of the variable is ");
	add_v3(&s, &d, &e);
	printValueOfAddress(&s);
	printf("\n");

	printf("Testing labwork function ...\n");
	int max, min, avg;
	int size = 5;
	int arr[] = {1, 2, 3, 4, 5};
	labwork6(&max, &min, &avg, arr, size);
	printf("max: %d, min: %d, avg: %d\n", max, min, avg);
	printf("\n");

	// TODO: Write test codes for all add functions

	printf("Testing swap function ...\n");
	int g = 45;
	int h = -7;
	printf("The first number is %d and the second one is %d\n", g, h);
	swap(&g, &h);
	printf("Swapping ...\n");
	printf("The first number is %d and the second one is %d\n", g, h);

	return 0;
}
