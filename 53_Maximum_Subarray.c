int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubArray(int* nums, int numsSize) {
    int currentSum = nums[0]; // maximum sum ending at current index
    int ans = nums[0];

    for (int i = 1; i < numsSize; i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        ans = max(ans, currentSum);
    }

    return ans;
}
