int missingNumber(int* nums, int numsSize) {
    int i = 0;
    while(i<numsSize){
        if(nums[i]>=0 && nums[i]<numsSize && nums[i]!=i && nums[i] != nums[nums[i]]){
            int temp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = temp;
        }
        else i++;
    }
    for(int i = 0; i<numsSize; i++){
        if(nums[i]==i){
            continue;
        }
        else{
            return i;
        }
    }
    return numsSize;
}