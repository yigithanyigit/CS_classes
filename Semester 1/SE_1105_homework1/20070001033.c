#include <stdio.h>
#include <math.h>


void printDigits(int number){
    /*
    params:
    number(int) 

    returns: None


    "This function prints digits of the given number"

    */
    int x = 1;
    int digit;
    while(number){
        if ( number < 10) {
            digit = number % 10;
            printf("%d", digit);
            number = number / 10;
        } else {
            digit = number % 10;
            printf("%d", digit);
            number = number / 10;
            if(x % 2 == 1) {
                printf(":");
            }
            x++;
        }
    }
}

int digitsSum(int number){
    /*
    params:
    number(int)

    returns:
    digitSum(int)

    "This function returns summary of all digits"

    */

    int digitSum = 0;
    int digit;
    while(number){
        digit = number % 10;
        number = number / 10;
        digitSum += digit;
    }
    return digitSum;
}

int main(){
   int n;

    printf("Please type a number ");
    scanf_s(" %d", &n);

    if (n <= 0){
        printf("Please type a positive value\n");
        main();
    }

    for (int i = 1; i <=n; i++){
        int digitSum = digitsSum(i);
        if (pow(sqrt(digitSum), 2) == digitSum){
            printf("%d ", i);
            printDigits(i);
            printf(" %d", digitSum);
            printf("\n");
        }
    }

    return 0;
}

