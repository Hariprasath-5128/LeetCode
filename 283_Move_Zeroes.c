void moveZeroes(int* nums, int numsSize) {
    int ptr = 0;
    for(int i = 0; i<numsSize; i++){
        if(nums[i] != 0){
            int temp = nums[ptr];
            nums[ptr] = nums[i];
            nums[i] = temp;
            ptr++;
        }
    }
}