int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int minimumDifference(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int i=0;
    int ans=INT_MAX;
    
    for(i = 0; i+k<numsSize; i++){
        ans= fmin(ans, nums[i+k-1] - nums[i]); //take min and max elements of the sliding window
    }
    if(i!=numsSize){
        ans = fmin(ans, nums[numsSize-1] - nums[i]);
    }
    return ans;
}
