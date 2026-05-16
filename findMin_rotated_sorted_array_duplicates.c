int findMin(int* nums, int numsSize) {
    int high = numsSize - 1;
    int low = 0;

    while(high > low){
        int mid = (low + high)/2;

        if(nums[mid] > nums[high]){
            low = mid + 1;
        }
        else if(nums[low] > nums[mid]){
            high = mid;
        }
        else{
            high--;
        }
    }
    return nums[low]; //narrow down with all necessary conditions clearly
}
