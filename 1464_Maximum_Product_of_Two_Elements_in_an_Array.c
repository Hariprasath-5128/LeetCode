#include <limits.h>

int maxProduct(int* nums, int numsSize) {

    int firstMax = INT_MIN;
    int secondMax = INT_MIN;
    int firstMin = INT_MAX;
    int secondMin = INT_MAX;

    for(int i = 0; i < numsSize; i++){
        if(firstMax <= nums[i]){
            secondMax = firstMax;
            firstMax = nums[i];
        }
        else if(secondMax <= nums[i]){
            secondMax = nums[i];
        }

        if(firstMin >= nums[i]){
            secondMin = firstMin;
            firstMin = nums[i];
        }
        else if(secondMin >= nums[i]){
            secondMin = nums[i];
        }
    }
    // Calculate both products safely
    long long posProd = (long long)(firstMax - 1) * (secondMax - 1);
    long long negProd = (long long)(firstMin - 1) * (secondMin - 1);

    // Return the absolute maximum product using a ternary operator
    return (posProd > negProd) ? (int)posProd : (int)negProd;
}
