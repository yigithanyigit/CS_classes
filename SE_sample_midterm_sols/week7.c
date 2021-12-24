#include "stdio.h"
#include "stdbool.h"


int func2()
{
	int a = 2;
	int b = 1;
	return a + b;
}

int func()
{
	int a = 3 * func2();
	return a;
}

void main_old()
{
	int x = 4;
	int y = 3;


	if (x > 5)
	{
		int y = 5;
		printf("%d\n", y); // The one that is most recently defined is printed.
	}


	int b = func();

	
}

void swap(int a, int b)
{
	int z = a;
	a = b;
	b = z;
}

void main_swap()
{
	int x = 7;
	int y = 9;

	printf("x : %d\n",x);
	printf("y : %d\n",y);

	swap(x, y);

	printf("x : %d\n", x);
	printf("y : %d\n", y);
}


double average(double p1, double p2)
{
	return (p1 + p2) / 2;
}

void main_avg()
{
	double d1 = 3.7;
	int d2 = 4;
	int x = 5;


	printf("The average of %.1f and %d is %.1f\n", d1,d2, average(d1,d2));

}




void main_arr()
{
	int a[5];  // Creating an integer array of length 5

	a[2] = 7;// Writing into an element
	a[0] = 1;

	a[1] = a[0] + a[2];


	printf(" %d\n", a[2]);

	int b[7] = { 3,3,3,3,3,3,3 }; 

	int c[1000];
	for (int x = 0; x<1000; x = x+1)
	{
		c[x] = 0;
	}

	double d_arr[] = {1.0,2.5};



}


//Write a function that returns the average of elements in an array
double averageOfArray(double arr[], int length)
{
	double sum= 0.0;
	for (int finger = 0; finger <length; finger++)
	{
		sum = sum + arr[finger];
	}
	return sum / length;
	
}


// Write a function that returns the maximum element of an array
double max(double d[], int len)
{
	double max = d[0];
	for (int i = 1; i < len; i++)
	{
		if (max < d[i])
		{
			max = d[i];
		}
	}

	return max;
}

// Write a function that prints an integer array on the screen.
void printArray(int arr[], int len)
{
	printf("{%d",arr[0]);
	for (int i = 1; i < len; i++)
	{
		printf(",%d",arr[i]);
	}
	printf("}\n");
}



// Write a function that calculates m*n without *
int multWithoutmult(int m, int n)
{
	int result = 0;

	for (int i = 0; i < n; ++i)
	{
		result = result + m;
	}

	return result;
}





void main_exercises()
{
	double d[] = { 1.4, 0.9, -4.2 };
	double d2[] = { 1.4, 0.9, -4.2 , 4.8, 11.0};

	int a[] = { 1,7,3,0,2 };

	printf("The average is %f\n", averageOfArray(d2, 5));
	printf("The maximum is %f\n", max(d2, 5));
	printArray(a, 5);
}

// Write a function that calculates m*n without * and / and without loops
int mult(int m, int n)
{
	if (n == 0)
		return 0;
	return m + mult(m, n - 1);
}

// Write a function that calculates the factorial of a given number
int factorial(int m)
{
	if (m == 3)
		return 6;
	return m * factorial(m - 1);
}

void main()
{
	int x = 4;
	int y = 7;

	printf("Thre mmult is :%d\n", mult(x, y));
}