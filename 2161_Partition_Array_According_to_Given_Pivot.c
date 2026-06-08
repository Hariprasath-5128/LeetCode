int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int k = 0;
    
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] < pivot) {
            ans[k++] = nums[i];
        }
    }

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == pivot) {
            ans[k++] = nums[i];
        }
    }

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > pivot) {
            ans[k++] = nums[i];
        }
    }

    *returnSize = numsSize;
    return ans;
}
