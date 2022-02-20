#include <stdlib.h>

#include "stdio.h"
#include "stdbool.h"
#include "windows.h"


// Pointer Intro
void main_intro()
{
	int a = 5;
	int c = 'B';

	printf("a:%d\n", a);
	printf("c:%c\n", c);

	int* p1 = &a;
	char* p2 = &c;

	printf("p1:%d\n", p1);
	printf("p2:%d\n", p2);

	printf("*p1:%d\n", *p1);
	printf("*p2:%c\n", *p2);

	*p1 = 2;
	*p2 = 'A';

	printf("a:%d\n", a);
	printf("c:%c\n", c);

	printf("p1:%d\n", p1);
	printf("p2:%d\n", p2);

	p1++;
	p2++;

	printf("p1:%d\n", p1);
	printf("p2:%d\n", p2);

}


// Pointer Arithmetic
void main_pa()
{
	int x = 1053;

	// Assigning an integer's address to a character pointer
	char* p = (char*)&x; 

	printf("p:%d\n", p);
	printf("*p:%d\n", *p); // Reading the memory as if there is a character there

	printf("*(p+1):%d\n", *(p+1)); // Accessing the 2nd byte of the integer

}

// Generic Pointer
void main_generic()
{
	int x = 4;
	char c = 6;
	double d = 7.0;

	void* p = &x;
	p = &c;
	p = &d;

	char* pc;

	pc =(char*) p;


}

void main_pp()
{
	int x = 5;

	int* px = &x;



	int** ppx = &px; // Pointer - to - pointer

	int*** pppx = &ppx;


	printf("x:%d\n", x);
	printf("px:%d\n", px);
	printf("ppx:%d\n", ppx);

	printf("*px:%d\n", *px);  // Value of x
	printf("*ppx:%d\n", *ppx); // Address of x
	printf("**ppx:%d\n", **ppx); // Value of x

	printf("*&*&*&(*(&(*ppx))):%d\n", *&*&*&*&*ppx); // Adress of x
}

void swap( int *px, int *py)
{
	int z = *px;
	*px = *py;
	*py = z;
}


void main_swap()
{
	int x = 6;
	int y = 1;

	printf("x:%d\n", x);
	printf("y:%d\n", y);

	swap(&x,&y);

	printf("x:%d\n", x);
	printf("y:%d\n", y);


}


// Pointers and arrays
void main_arrr()
{
	int arr[] = { 1,0,2,4,8 };

	int *p = &arr[0]; // Addr. of the first element is assigned to p

	p++; // p is pointing at the2nd element

	p = arr; // addr. of the first element is assigned to p again

	printf("arr[0]:%d\n", arr[0]);
	printf("arr:%d\n", arr);
	printf("*arr:%d\n", *arr);
	printf("*(arr+1):%d\n", *(arr+1));

	printf("p:%d\n", p);
	printf("*p:%d\n", *p);
	printf("p[2]:%d\n", p[2]);

}

void printArray(int *arr ,int len)
{
	


	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
}


void main_array_as_parameter()
{
	int arr[] = { 1,0,3,7,2,8 };

	printArray(arr,6);

}


void print(char str[])
{
	for (; *str != NULL; str++)
	{
		printf("%c", *str);
	}
}



// Write strlen function with pointers

int strLen(char * str)
{
	int counter = 0;
	for (; *str != NULL; str++)
	{
		counter++;
	}
	return counter;
}

// Write a function that returns if a given string is palindrome
bool isPalindrome(char *str)
{
	char* pl = str;
	char* pr = str + strLen(str)-1;

	for (;   pl<pr;  pl++, pr--)
	{
		if (*pl != *pr)
			return false;
	}

	return true;
}

void main_string()
{
	char str[] = "HHHHHHHHHHHHHHHHHH---HHHHHHHHHHH";

	if (isPalindrome(str))
		printf("Palindrome\n");
	else printf("NOT!\n");

}



void waitForSomeTime()
{
	Sleep(100);
}


void main_memoryLeak()
{
	// DO NOT DO THIS!
	while (true)
	{
		int* p = (int*)malloc(sizeof(int));// Memory Leak
		*p = 4;
		int x = 8;
		p = &x;
	}
}


// Red n numbers from the user and print in reverse order
void printNumbers(int n)
{
	printf("Enter %d numbers:\n",n);
	int* p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &p[i]);
	}

	for (int i = n-1; i >=0; i--)
	{
		printf("%d\n",p[i]);
	}

	free(p);
}

void main()
{
	/*
	int* p = malloc(sizeof(int) * 10000000);

	p[0] = 5;
	p[900000] = 13;

	free(p);


	printNumbers(5);
	*/
	main_intro();


}
