#include <stdio.h>


/**
  * function: fillArray
  * -------------------
  * This function is used to fill the array given as a 
  * parameter according to the user's request. In each 
  * iteration, the program will press the screen to "enter 
  * the number 1': " (1 increases in each iteration) number 
  * and get a number from the user, then assign that number 
  * to the relevant index of the array.
  * @param array -> integer array given as input
  * @param size  -> size of given array
  */
void fillArray(int array[], int size) {
	// TODO: Fill
  for (int i = 0; i <= size - 1 ; i++){
    printf("enter the number %d \n", i);
    scanf_s(" %d", &array[i]);
  }
}


/**
  * function: printArray
  * --------------------
  * This function prints each element in the array 
  * sequentially. Prints a comma after every element except 
  * the last element. It also prints a newline after all 
  * elements are printed.
  * @param array -> integer array given as input
  * @param size  -> size of given array
  */
void printArray(int array[], int size) {
	// TODO: Fill
  for (int i = 0; i <= size - 2; i++){
    printf("%d,", array[i]);
  }
  printf("%d \n", array[size - 1]);
}


/**
  * function: showMax
  * -----------------
  * This function prints the highest element in the given 
  * integer array to the screen.
  * @param array -> integer array given as input
  * @param size  -> size of given array
  */
void showMax(int array[], int size) {
	// TODO: Fill
  int result = 0;
  for (int i = 0; i <= size - 1; i++){
    if(array[i] > result){
      result = array[i];
    }
  }
  printf("%d\n", result);
}


/**
  * function: calculateAvg
  * ----------------------
  * This function returns the average of a given integer 
  * array in double data type.
  * @param array -> integer array given as input
  * @param size  -> size of given array
  * @return      -> the average of the elements in the 
  *                 integer array as double data type
  */
double calculateAvg(int array[], int size) {
	// TODO: Fill
  int sum;
  for (int i = 0; i <= size - 1; i++){
      sum += array[i];
    }
    
	return sum/size;
}


/**
  * function: searchArray
  * ---------------------
  * This function checks whether the elements in the given 
  * integer array are the same by comparing the given key. 
  * If the same, the function equalizes the variable to be 
  * returned with the index. If there is no key in the 
  * array, the function returns -1.
  * @param array -> integer array given as input
  * @param key   -> key to search in array
  * @param size  -> size of given array
  * @return      -> if exists, the index of the key in the 
  *                 array; if not exists, -1
  */
int searchArray(int array[], int key, int size) {
	  for (int i = 0; i <= size - 1; i++){
      if(key == array[i]){
        return i;
      }
    }
    return -1;
}



int main() {
	int grade[10];
	
	fillArray(grade, 10);
	
	printArray(grade, 10);
	
	showMax(grade, 10);
	
	double avg = calculateAvg(grade, 10);
	printf("%f\n", avg);
	
	int key;
	printf("Enter the grade will be searched: ");
	scanf("%d", &key);
	int index = searchArray(grade, key, 10);
	if (index == -1) {
		printf("There is no that grade in the array.\n");
	}
	else {
		printf("This key exists in the %dth index of the array.\n", index);
	}
	
	return 0;
}
