#include <stdio.h>

int solve(int a, int b, int c){
    int sums[] = {a - b, a - c, b - c};
    int result = sums[0];
    for(int i = 1; i <= 3; i++){
        if (sums[i] > 0){
            if (sums[i] < result){
                result = sums[i];
            }
        }
        else {
            if (-sums[i] < result){
            result = -sums[i];
            }
        }
    }
    return result;
}


int main(){
    printf("%d", solve(5,3,9));
return 0;
};