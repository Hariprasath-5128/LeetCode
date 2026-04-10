<<<<<<< HEAD
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
=======
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
>>>>>>> c32e7d35f26fa141d7aecb662d6a8da5e5333b23
}