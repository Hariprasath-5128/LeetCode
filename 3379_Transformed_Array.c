/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {

    int *result = (int *)malloc(numsSize * sizeof(int));
    memset(result, 0, numsSize * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        int steps = nums[i];

        if(steps > 0){
            int ptr = (i + steps) % (numsSize);
            result[i] = nums[ptr];
        }

        else if(steps < 0){
            int ptr = ((i + steps) % numsSize + numsSize) % numsSize; // Works even with abs(steps) > numsSize
            result[i] = nums[ptr];
        }

        else{
            result[i] = nums[i];
        }
    }

    *returnSize = numsSize;
    return result;
}
