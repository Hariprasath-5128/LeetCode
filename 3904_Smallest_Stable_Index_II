class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int numsSize = nums.length;
        int[] prefixMin = new int[numsSize];
        int[] prefixMax = new int[numsSize];

        int min =  nums[numsSize - 1];
        int max = 0;
        for(int i = 0; i < numsSize; i++){

             if(max < nums[i]){
                max = nums[i];
            }
            prefixMax[i] = max;

        }
        for(int i = numsSize-1; i >=0 ; i--){

            if(min > nums[i]){
                min = nums[i];
            }
            prefixMin[i] = min;
        }

        for(int i = 0; i < numsSize; i++){
            if(prefixMax[i] - prefixMin[i] <= k)
                return i;
        }

        return -1;
    }
}
