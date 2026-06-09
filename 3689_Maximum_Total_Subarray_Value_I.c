long long maxTotalValue(int* nums, int numsSize, int k) {
    long long max = INT_MIN;
    long long min = INT_MAX;

    for(int i = 0; i< numsSize; i++){
        if(max < nums[i])
            max = nums[i];
        if(min > nums[i])
            min = nums[i];
    }

    return (max-min)*k;
}
