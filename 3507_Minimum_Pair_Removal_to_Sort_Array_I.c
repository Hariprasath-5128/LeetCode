#include <stdbool.h>

bool isSorted(int* nums, int numsSize){
    for(int i = 1; i<numsSize; i++){
        if(nums[i]<nums[i-1]){
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int ops = 0;

    while(!isSorted(nums, numsSize)){
        int idx = 0;
        int min = nums[0] + nums[1];

        for(int i = 1; i<numsSize-1; i++){
            int sum = nums[i]+nums[i+1];

            if(sum < min){
                min = sum;
                idx = i;
            }
        }
        nums[idx] = min;

        for(int i = idx+1; i<numsSize-1; i++){
            nums[i] = nums[i+1];
        }
        numsSize--;
        ops++;
    }
    return ops;
}
