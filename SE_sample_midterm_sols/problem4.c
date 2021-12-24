#include <stdio.h>

int solve(int arr1[], int arr2[], int size){
    int sum = 0;
    int sumarr[size];
    for(int i = 0; i <= size - 1 ; i++)
    {
        for(int q = 0; q <= size - 1 ; q++){
            if(arr1[i] == arr2[q]){
                if(i >= q){
                sum += 1;
                sumarr[i] = i;
                }
            }
        }
    }
    printf("%d \n", sum);
    return sumarr;
}
int main(){
    int arr1[] = {1,5,2,3,4,0,7}, arr2[] = {0,1,3,7,4,2};
    int x = solve(arr1, arr2, 7);
    printf("%d", x);
    return 0;
};