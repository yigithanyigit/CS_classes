#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int strLength(char str[]) {
    int length = 0;
    while( str[length] != '\0' ) {
        length++;
    }
    return length;
}

void printStr(char str[]){
    int i;
    int length = strLength(str);
    for(i = 0; i < length; i++) {
        printf("%c",str[i]);
    }
    printf("\n");
}

void toUpper(char str[]){
    int i;
    int diff = 'a' - 'A'; // 97 - 65 = 32
    int length = strLength(str);

    for(i = 0; i < length; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') { // if lowercase
            str[i] = str[i] - diff;
        }
    }
}

void toLower(char str[]){
    int i;
    int diff = 'a' - 'A'; // 97 - 65 = 32
    int length = strLength(str);

    for(i = 0; i < length; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') { // if lowercase
            str[i] = str[i] + diff;
        }
    }
}

void copyStr(char str[], char copy[]){
    int i;
    int length = strLength(str);
    for(i = 0; i < length; i++) {
        copy[i] = str[i];
    }
    copy[length] = '\0';
}

void appendStr(char str1[], char str2[], char result[]){
    int length1 = strLength(str1);
    int length2 = strLength(str2);
    int i;

    for(i = 0; i < length1; i++) {
        result[i] = str1[i];
    }

    for(i = 0; i < length2; i++) {
        result[length1 + i] = str2[i];
    }
    result[length1 + length2] = '\0';

    /*
    for(; i < length1 + length2; i++) {
    result[i] = str2[i - length1];
    }
    */
}

void encode(char str[], int key){
    int i;
    int length = strLength(str);
    for(i = 0; i < length; i++) {
        str[i] = str[i] + key;
    }
}

void decode(char str[], int key){
    int i;
    int length = strLength(str);
    for(i = 0; i < length; i++) {
        str[i] = str[i] - key;
    }
}

void main() {
    /*
    char str[MAX_LENGTH] = "This is a message";
    char str2[MAX_LENGTH];

    printf("Length: %d\n", strLength(str));
    printStr(str);

    toUpper(str);
    printStr(str);
    toLower(str);
    printStr(str);

    copyStr(str, str2);
    printStr(str2);

    char str1[MAX_LENGTH] = "SE";
    char str2[MAX_LENGTH] = "1105";
    char result[MAX_LENGTH];

    appendStr(str1, str2, result);
    printStr(result);
    */

    char text[MAX_LENGTH] = "MESSAGE";

    printf("Plain Text: ");
    printStr(text);

    encode(text, 3);
    printf("Encoded Text: ");
    printStr(text);

    decode(text, 3);
    printf("Decoded Text: ");
    printStr(text);

}
