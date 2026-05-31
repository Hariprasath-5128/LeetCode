int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(nums[mid] == target)
            return mid;

        if(nums[mid] > target)
            high = mid;
        else
            low = mid + 1;
    }

    if(nums[numsSize - 1] < target)
        return numsSize;

    return low;
}
