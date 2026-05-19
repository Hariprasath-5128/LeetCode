/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxValue(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;
    int n = numsSize;

    int* ans = (int*)malloc(sizeof(int) * n);
    int* prefixMax = (int*)malloc(sizeof(int) * n);
    int* suffixMin = (int*)malloc(sizeof(int) * n);

    int curr_max = nums[0], curr_min = nums[n-1];

    // prefixMax[i] = maximum value from 0 to i
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > curr_max){
            curr_max = nums[i];
        }
        prefixMax[i] = curr_max;
    }

    // suffixMin[i] = minimum value from i to n-1
    for(int i = numsSize - 1; i >= 0; i--){
        if(nums[i] < curr_min){
            curr_min = nums[i];
        }
        suffixMin[i] = curr_min;
    }

    int start = 0;
    int currentMax = nums[0];

    for(int i = 0; i < numsSize; i++){

        if(nums[i] > currentMax){
            currentMax = nums[i];
        }

        // if max(left part) <= min(right part),
        // no inversion exists across boundary,
        // so component breaks here
        if(i == n-1 || prefixMax[i] <= suffixMin[i+1]){

            // all indices inside same component
            // get same maximum reachable value
            for(int j = start; j <= i; j++)
                ans[j] = currentMax;

            start = i + 1;

            if(start < n)
                currentMax = nums[start];
        }
    }

    free(prefixMax);
    free(suffixMin);

    return ans;
}
