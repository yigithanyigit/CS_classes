#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000 // **** do not edit the macro  ****

typedef struct
{ // **** do not edit the struct ****
	int film_id;
	char title[255];
	char description[1023];
	unsigned int release_year;
	char rental_duration;
	float rental_rate;
	unsigned char length;
	float replacement_cost;
	char rating[10];
	char last_update[30];
} RECORD_t, *RECORD;

float average_rental_rate(RECORD records);
float average_release_year(RECORD records);
RECORD find_top_ten_films(RECORD records);
RECORD find_ten_affordable_films(RECORD records);

int main()
{
	// *****************************************************
	// *************** DO NOT EDIT THIS PART ***************
	RECORD records = (RECORD)malloc(sizeof(RECORD_t) * MAX);
	FILE *file = fopen("records.txt", "rb");
	if (file == NULL)
	{
		printf("Cannot open the file.\n");
		exit(0);
	}
	fread(records, sizeof(RECORD_t) * MAX, 1, file);
	fclose(file);
	// *****************************************************

	// *****************************************************
	// YOUR CODE GOES HERE!


	float avg_rate = average_rental_rate(records);

	printf("average rental rate: %f\n", avg_rate);

	float avg_year = average_release_year(records);

	printf("average release year: %f\n", avg_year);

	RECORD a = find_top_ten_films(records);
	/*
	// *****************************************************
	// DEBUG


	for (int c = 0; c < 10; c++)
	{
		printf("%d\n", a[c].film_id);
		printf("%s\n\n", a[c].title);
	}
	*/
	// DEBUG END
	// *****************************************************

	FILE *file1 = fopen("records_top_ten.txt", "w");
	if (file1 == NULL)
	{
		printf("Cannot open the file.\n");
		exit(0);
	}
	for (int c = 0; c < 10; c++)
	{
		fwrite(&a[c].title, strlen(a[c].title), 1, file1);
		fwrite("\n", strlen("\n"), 1, file1);
	}

	fclose(file1);
	free(a);

	RECORD b = find_ten_affordable_films(records);

	FILE *file2 = fopen("records_affordables.txt", "w");
	if (file2 == NULL)
	{
		printf("Cannot open the file.\n");
		exit(0);
	}
	for (int c = 0; c < 10; c++)
	{
		fwrite(&b[c].title, strlen(b[c].title), 1, file2);
		fwrite("\n", strlen("\n"), 1, file2);
	}

	fclose(file2);
	free(b);
	// *****************************************************

	return 1;
}

float average_rental_rate(RECORD records)
{
	int i;
	float q;

	for (i = 0; i < MAX; i++)
	{
		q += records[i].rental_rate;
	}
	return q / MAX;
}

float average_release_year(RECORD records)
{
	int i;
	float q;

	for (i = 0; i < MAX; i++)
	{
		q += records[i].release_year;
	}

	return q / MAX;
}

RECORD find_top_ten_films(RECORD records)
{

	int i, q, max;
	RECORD d = (RECORD_t *)malloc(sizeof(RECORD_t) * 10);

	// *******************************
	// Perfect situation approach
	/*
	for (i = 0, q = 0, max = 11; i < MAX; i++)
	{
		if (records[i].film_id < max)
		{
			printf("%d ", records[i]);
			d[q] = records[i];
			q++;
		}

	}
	 */
	// ******************************

	int flag = -1;
	RECORD tempArr = (RECORD_t *)malloc(sizeof(RECORD_t) * MAX);
	for (i = 0; i < MAX; i++)
	{
		tempArr[i] = records[i];
	}

	for (i = 0; i < 10; i++)
	{
		int temp = records[0].film_id;
		int index = 0;
		for (q = 0; q < MAX; q++)
		{
			if (tempArr[q].film_id < temp && tempArr[q].film_id != flag)
			{
				index = q;
				temp = tempArr[q].film_id;
			}
		}
		d[i] = records[index];
		tempArr[index].film_id = flag;
	}

	return d;
}

RECORD find_ten_affordable_films(RECORD records)
{

	RECORD d = (RECORD_t *)malloc(sizeof(RECORD_t) * 10);
	float rate = average_rental_rate(records);
	float year = average_release_year(records);
	int i, q = 0;
	for (i = 0; i < MAX, q < 10; i++)
	{
		if (records[i].rental_rate < rate && records[i].release_year > year)
		{
			d[q] = records[i];
			q++;
		}
	}

	return d;
}