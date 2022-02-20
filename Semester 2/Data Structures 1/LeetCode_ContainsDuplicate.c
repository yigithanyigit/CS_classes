#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comparator(const void* elem1, const void* elem2){
    int f = *((int*)elem1);
    int q = *((int*)elem2);
    
    if (f > q) return 1;
    if (f < q) return -1;
    return 0;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(*nums), comparator);
    if(numsSize < 2) return false;
    
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] == nums[i + 1]){
            printf("true %d  %d",nums[i], nums[i + 1]);
           return true; 
           
        } 
        else {
            printf("false %d  %d\n",nums[i], nums[i + 1]);
        }
    }
    return false; 
}

int main(){
    int* nums[] = {2,14,18,22,22};
    int numsSize = 5;
    printf("%d\n",containsDuplicate(nums, 5));
   // printf("%d\n",nums[0]);

}