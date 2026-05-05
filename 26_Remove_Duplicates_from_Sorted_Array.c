int removeDuplicates(int* nums, int numsSize) {
    int first = 0;
    int second = 1;
    int arr[numsSize];
    int k = 0;
    while(numsSize>second){
        if (nums[first] == nums[second]){
            second++;
        }
        else{
            arr[k++] = nums[first];
            first = second;
            second++;
        }
    }
    arr[k++] = nums[first]; /* For adding the last unique element*/
    
    for(int i = 0; i<k; i++){
        nums[i] = arr[i];
    }
    return k;
}