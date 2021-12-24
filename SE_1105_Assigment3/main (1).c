#include "stdio.h"
#include "stdbool.h"


// Print all characters with their ASCII code

void printAllChars()
{
	for (int i = 0; i < 256; ++i)
	{
		printf("%d : %c \n", i, i);
	}
}

// Returns the capital version of a given small letter. If c is not small letter
// it returns c
char capitalize(char c)
{
	int delta = 'a' - 'A';
	if (c >= 'a' && c <= 'z')
		return c - delta;
	else return c;
}

void printCharArray(char arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%c", arr[i]);
	}
}

void printString(char arr[])
{
	for (int i = 0;  arr[i] != NULL ; ++i)
	{
		printf("%c", arr[i]);
	}
}

void capitalizeString(char str[])
{
	for (int i = 0; i < str[i]!=0; ++i)
	{
		str[i] = capitalize(str[i]);
	}
}

// Write a function that returns the length of a string
int strLen(char str[])
{
	int i = 0;
	for (; str[i] != '\0'; ++i);

	return i;
}


// Write a function that takes a string (str) and two characters namely
// c1 and c2 as parameters. The function must replace every occurrence of c1
// in str with c2.
void replaceAll(char str[], char c1, char c2)
{
	for (int i = 0; i < str[i] != 0; ++i)
	{
		if (str[i]== c1)
			str[i] = c2;
	}
}


// Write a function that returns if two strings are equal.
bool isEqual(char s1[], char s2[])
{
	int i = 0;
	for (; s1[i] != NULL && s1[i] == s2[i]; ++i);
	
	return s1[i] == s2[i];
	
}


// Write a function that compares two strings
// s1 and s2 alphabetically. If s1 > s2 1 if s1<s2 -1 if s1 == s2 0


void main()
{
	char arr[] = { 'H', 'e', 'l', 'l','o','\n' ,NULL};

	char str[] = "Hello\n";

	printString(arr);

	replaceAll(str, 'l', 'B');

	printString(arr);

	printf(str);

}