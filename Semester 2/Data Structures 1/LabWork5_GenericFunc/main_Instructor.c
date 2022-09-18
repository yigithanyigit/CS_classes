#include <stdio.h>
#include<stdlib.h>



#define SIZE 10

void print_arr_int(int work[], const int size);
void swap_int(int *element1Ptr, int *element2ptr);
void bubble_int_asc(int work[], const int size);
void bubble_int_desc(int work[], const int size);
void bubble_int(int work[], const int size, int (*compare)(int, int));
int compare_int_asc(int x, int y);
int compare_int_desc(int x, int y);

void swap(void **p1, void **p2);
void bubble(void *work[], const int size, int (*compare)(void*, void*));
void print_arr_str(char *a[], int size);
int compare_str_asc(void *x, void *y);
int compare_str_desc(void *x, void *y);

#define NAME_SIZE 50
typedef struct STUDENT_s {
	int id;
	char name[NAME_SIZE];
} STUDENT_t, *STUDENT;
void print_arr_STUDENT(STUDENT a[], int size);
int compare_STUDENT_name_asc(void *x, void *y);



int main_sort_int() {
	int counter;
	int a[SIZE] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
	
	print_arr_int(a, SIZE);
	printf("\n");
	
	bubble_int_asc(a, SIZE);
	print_arr_int(a, SIZE);
	printf("\n");
	
	bubble_int_desc(a, SIZE);
	print_arr_int(a, SIZE);
	printf("\n");
	
	bubble_int(a, SIZE, &compare_int_asc);
	print_arr_int(a, SIZE);
	printf("\n");
	
	bubble_int(a, SIZE, &compare_int_desc);
	print_arr_int(a, SIZE);
	printf("\n");
	
	bubble(a, SIZE, &compare_int_asc);
	print_arr_int(a, SIZE);
	printf("\n");
	
	return 0;
}

int main_sort_str() {
	char *a[SIZE] = {"lkasj", "l2342k", "asjflk", "243234jllppqq", "alskfjlak2432",
	"934sjflk", "a", "", "jsflkjaslf", "k9832986347834"};
	
	print_arr_str(a, SIZE);
	printf("\n");
	
	bubble((void *)a, SIZE, compare_str_asc);
	print_arr_str(a, SIZE);
	printf("\n");
	
	bubble((void *)a, SIZE, compare_str_desc);
	print_arr_str(a, SIZE);
	printf("\n");
}

int main_sort_struct() {
	STUDENT a[SIZE];
	int i;
	STUDENT t;
	
	for(i=0; i<SIZE; i++) {
		t = (STUDENT)malloc(sizeof(STUDENT_t));
		t->id = SIZE-i;
		itoa(i, t->name, 2);
		a[i] = (void *)t;
	}
	print_arr_STUDENT(a, SIZE);
	printf("\n");
	
	bubble((void *)a, SIZE, compare_STUDENT_name_asc);
	print_arr_STUDENT(a, SIZE);
	printf("\n");
	
	for(i=0;i>SIZE; i++) {
		free(a[i]);
	}
	
}

int main() {
	main_sort_int();
	main_sort_str();
	main_sort_struct();
}



void print_arr_int(int work[], const int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("%d ", work[i]);
	}
}

/* swap values at memory locations to which element1Ptr and element2Ptr point */
void swap_int(int *element1Ptr, int *element2Ptr) {
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}

void bubble_int_asc(int work[], const int size) {
	int pass, count;
	/* loop to control passes */
	for (pass = 1; pass < size; pass++) {
		/* loop to control number of comparisons per pass */
		for (count = 0; count < size - 1; count++) {
			/* if adjacent elements are out of order, swap them */
			if (work[count] > work[count+1]) {
				swap_int(&work[count], &work[count + 1]);
			}
		}
	}
}

void bubble_int_desc(int work[], const int size) {
	int pass, count;
	/* loop to control passes */
	for (pass = 1; pass < size; pass++) {
		/* loop to control number of comparisons per pass */
		for (count = 0; count < size - 1; count++) {
			/* if adjacent elements are out of order, swap them */
			if (work[count] < work[count+1]) {
				swap_int(&work[count], &work[count + 1]);
			}
		}
	}
}

void bubble_int(int work[], const int size, int (*compare)(int, int)) {
	int pass, count;
	/* loop to control passes */
	for (pass = 1; pass < size; pass++) {
		/* loop to control number of comparisons per pass */
		for (count = 0; count < size - 1; count++) {
			/* if adjacent elements are out of order, swap them */
			if ((*compare)(work[count], work[count+1]) > 0) {
				swap_int(&work[count], &work[count + 1]);
			}
		}
	}
}

int compare_int_asc(int x, int y) {
	return x-y;
}

int compare_int_desc(int x, int y) {
	return y-x;
}

void swap(void **p1, void **p2) {
	void *tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void bubble(void *work[], const int size, int (*compare)(void*, void*)) {
	int pass, count;
	/* loop to control passes */
	for (pass = 1; pass < size; pass++) {
		/* loop to control number of comparisons per pass */
		for (count = 0; count < size - 1; count++) {
			/* if adjacent elements are out of order, swap them */
			if ((*compare)(work[count], work[count+1]) > 0) {
				swap(&work[count], &work[count + 1]);
			}
		}
	}
}

void print_arr_str(char *a[], int size) {
	int i;
	for(i=0; i<SIZE; i++) {
		printf("%s ", a[i]);
	}
}

int compare_str_asc(void *x, void *y) {
	char *s1 = (char *)x;
	char *s2 = (char *)y;
	return strcmp(s1, s2);
}

int compare_str_desc(void *x, void *y) {
	char *s1 = (char *)x;
	char *s2 = (char *)y;
	return -strcmp(s1, s2);
}

void print_arr_STUDENT(STUDENT a[], int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("(%d:%s) ", a[i]->id, a[i]->name);
	}
}

int compare_STUDENT_name_asc(void *x, void *y) {
	STUDENT s1 = (STUDENT)x;
	STUDENT s2 = (STUDENT)y;
	return strcmp(s1->name, s2->name);
}

