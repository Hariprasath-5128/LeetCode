#include <stdlib.h> 

int findClosestNumber(int* nums, int numsSize) {
    int result = -1;
    int min = 10000000;
    int minidx = -1;
    for(int i = 0; i<numsSize; i++){
        if(abs(nums[i]-0)<min){
            min=abs(nums[i]);
            result = nums[i];
            minidx = i;
        }
        if(nums[i]==min){
            if(nums[i]>result){
                result = nums[i];
                minidx = i;
            }
        }
    }
    return nums[minidx];
}