int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;
    while(i<numsSize){
        int ind = nums[i]-1;
        if(nums[i]>0 && nums[i]<=numsSize && nums[ind]!=nums[i]){
            int temp = nums[i];
            nums[i] = nums[ind];
            nums[ind] = temp;
        }
        else{
            i++;
        }
    }
    int result = 0;
    for(int i = 0; i<numsSize; i++){
        if(nums[i]!=i+1){
            return i+1;
        }
    }
    return numsSize+1;
}