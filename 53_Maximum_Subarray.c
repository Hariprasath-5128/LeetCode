int maxSubArray(int* nums, int numsSize) {
    int sum = 0, max_sum = -100000000000;
    for(int i = 0; i< numsSize; i++){
        sum+=nums[i];
        if(nums[i]>=sum){
            sum = nums[i];
        }
        if(max_sum < sum){
            max_sum = sum;
        }
    }
    return max_sum;
}