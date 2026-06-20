int minimumCost(int* nums, int numsSize) {
    //Defined 3 subarrays

    int min1 = INT_MAX, min2 = INT_MAX;
    
    //[0...index(min1)-1], [index(min1).....index(min2)-1], [index(min2)......numsSize-1]
    for(int i = 1; i<numsSize; i++){
        if(nums[i]<min1){
            min2 = min1;
            min1 = nums[i];
        }
        else if(nums[i]<min2)
            min2 = nums[i];
    }
    return nums[0] + min1 + min2;
}