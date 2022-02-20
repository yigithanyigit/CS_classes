int calculate_digits(int number){
    int digitsCounter = 0;;
    while(number){
        number % 10;
        number = number / 10;
        digitsCounter++;
    }
    return digitsCounter;
}

void solve(int digits, int number){
    int digit;
    int sum = 0;
    int constVersionOfNumber = number;
    while(number){
    int digitSum = 1;
    digit = number % 10;
    number = number / 10;
    for (int i = 0; i < digits; i++){
        digitSum *= digit;
        }
    sum += digitSum;
    }
    if (sum == constVersionOfNumber){
       printf("is armstrong\n");
    } else {
       printf("is not a armstrong\n");
    }
}

int main(){
    int var, digits; 
    printf("Please type a number ");
    scanf_s(" %d", &var);
    digits = calculate_digits(var);
    solve(digits, var);
    main();
    return 0;
}