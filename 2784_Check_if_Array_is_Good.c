#include <stdbool.h>

bool isGood(int* nums, int numsSize) {  

    int hash[1001] = {0};  

    for(int i = 0; i < numsSize; i++) {  
        hash[nums[i]]++;  
    }  

    bool isbase = true;  

    for(int i = 1; i <= numsSize - 2; i++) {  
        if(hash[i] != 1) {  
            isbase = false;  
            break;  
        }  
    }  

    if(hash[numsSize - 1] == 2 && isbase) {  
        return true;  
    }  

    return false;  
}
