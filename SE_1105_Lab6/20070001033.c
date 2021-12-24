#include <stdio.h>

// FUNCTIONS TO BE FILLED

/**
  * function: isPrime
  * -----------------
  * This function checks if a given number is prime.
  * @param a -> number to be tested for prime
  * @return  -> 0 if no prime, 1 if prime
  */
int isPrime(int a) {
    // we will use simple prime function checker concept, as you know prime numbers divisible
    // by 1 and itself so we can use that. We iterate all numbers to 'a'
    int found = 0;

    if(a < 2) return 0;

    for(int i = 2; i < a ; i++)
    {
        if(a % i == 0){
            found = 1;
            break;
        }     
    }
    if (found == 1){
        return 0;
    }	
    else return 1;
}

/**
  * function: fillArrayWithPrimes
  * -----------------------------
  * This function fills the given array with the prime numbers until the given 
  * number. The number of prime numbers filled into the array is returned at 
  * the end of the function.Note that the size of the given array is big enough.
  * @param arr -> the given array to be filled
  * @param n   -> upper limit of prime numbers to be filled
  * @return    -> how many prime numbers are filled into the array
  */
int fillArrayWithPrimes(int arr[], int n) {
    int iter = 0;
	for(int i = 0; i <= n; i++){
        if(isPrime(i) == 1){
            arr[iter] = i;
            iter += 1;
        }
        
    }
    return iter;
}

/**
  * function: squareRoot
  * --------------------
  * This function calculates its square root if the given number is a perfect 
  * square; returns -1 if the given number is not squareroot.
  * @param a -> given number
  * @return  -> if it is a perfect square then the square root, otherwise -1
  */
int squareRoot(int a) {
    for(int r=1;r * r<=a; r++) 
        { 
            if((r * r)==a) {
                return r;
            }
        }
        return -1; 
}

/**
  * function: printBox
  * ------------------
  * This function prints a box shape using 'X' and '.' characters to the 
  * screen. 'X' for lines at the edges and diagonal lines of the shape prints 
  * '.' for other places. The shape contains the equal number of characters for 
  * both rows and columns. A sample shape with a size of 11 is given below.
  * XXXXXXXXXXX
  * XX.......XX
  * X.X.....X.X
  * X..X...X..X
  * X...X.X...X
  * X....X....X
  * X...X.X...X
  * X..X...X..X
  * X.X.....X.X
  * XX.......XX
  * XXXXXXXXXXX
  * @param size -> size of the shape for both row and column
  */
 /*
void printBox(int size) {
	for(int y = 0; y < size; y++){
        for(int x =0; x < size; x++){
            if(( x == 0 || y == 0 || y == size -1))
            {
                printf("X");
            }
            else{
                if(x == size -1){
                    printf("X");
                }
                else if(((x + y) == size -1 || x - y == 0)){
                    printf("X");
                }else printf(".");
            }
        }
        printf("\n");
    }
}
*/
void printBox(int size) {
	for(int y = 0; y < size; y++){
        for(int x =0; x < size; x++){
            if(( x == 0 || y == 0 || y == size -1 || x == size - 1))
            {
                printf("X");
            }
            else{
                if(((x + y) == size -1 || x - y == 0)){
                    printf("X");
                }else printf(".");
            }
        }
        printf("\n");
    }
}


// TEST FUNCTIONS
// These functions are for testing only. You do not need to study or understand 
// these functions for this lab session.

void isPrimeTest() {
	int input[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 45, 313};
	int output[10] = {0, 1, 1, 0, 1, 0, 1, 0,  0,   1};
	int t = 0;
	int i;
	for (i = 0; i < 10; i = i + 1) {
		if (output[i] == isPrime(input[i])) {            
			t = t + 1;
		}
	}
	printf("isPrime function is probably %d0%% correct.\n", t);
}

void fillArrayWithPrimesTest() {
	int input[5] =  {3, 7, 15, 50, 101};
	int output[5] = {2, 4,  6, 15,  26};
	int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
	int t = 0;
	int i, j;
	for (i = 0; i < 5; i = i + 1) {
		int arr[32];
		int res = fillArrayWithPrimes(arr, input[i]);
		if (res == output[i]) {
			t = t + 1;
		}
		if (res > 0 && res < 32) {
			int s = 1;
			for (j = 0; j < res; j = j + 1) {
				if (primes[j] != arr[j]) {
					s = 0;
				}
			}
			t = t + s;
		}
	}
	printf("fillArrayWithPrimes function is probably %d0%% correct.\n", t);
}

void squareRootTest() {
	int input[10] =  { 3, 4, 25, 36, 100, 101, 121, 136, 200, 202};
	int output[10] = {-1, 2,  5,  6,  10,  -1,  11,  -1,  -1,  -1};
	int t = 0;
	int i;
	for (i = 0; i < 10; i = i + 1) {
		if (output[i] == squareRoot(input[i])) {
			t = t + 1;
		}
	}
	printf("squareRoot function is probably %d0%% correct.\n", t);
}


// MAIN FUNCTION
int main() {
	isPrimeTest();
	fillArrayWithPrimesTest();
	squareRootTest();
	
	printf("\n");
	printBox(7);
	/*
	XXXXXXX
	XX...XX
	X.X.X.X
	X..X..X
	X.X.X.X
	XX...XX
	XXXXXXX
	*/

	printf("\n");
	printBox(11);
	/*
	XXXXXXXXXXX
	XX.......XX
	X.X.....X.X
	X..X...X..X
	X...X.X...X
	X....X....X
	X...X.X...X
	X..X...X..X
	X.X.....X.X
	XX.......XX
	XXXXXXXXXXX
	*/
	printf("\n");
	printBox(12);
    /*
	XXXXXXXXXXXX
	XX........XX
	X.X......X.X
	X..X....X..X
	X...X..X...X
	X....XX....X
	X....XX....X
	X...X..X...X
	X..X....X..X
	X.X......X.X
	XX........XX
	XXXXXXXXXXXX
	*/

	return 0;
}
