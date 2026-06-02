void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxProduct(int* nums, int numsSize) {
    int maxEnding = nums[0]; //The maximum product of any subarray that MUST end at index i
    int minEnding = nums[0]; //The minimum product of any subarray that MUST end at index i
    int ans = nums[0];

    for(int i = 1; i<numsSize; i++){
        if(nums[i]<0){
            swap(&maxEnding, &minEnding); //Upto the current index, the maxEnding value now have the minEnding value (because of the negative nums[i])
        }
        maxEnding = max(nums[i]*maxEnding, nums[i]);
        minEnding = min(nums[i]*minEnding, nums[i]);

        ans = max(ans, maxEnding);
    }
    return ans;
}