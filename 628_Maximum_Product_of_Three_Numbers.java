class Solution {
    public int maximumProduct(int[] nums) {

        int first = Integer.MIN_VALUE, second = Integer.MIN_VALUE, third = Integer.MIN_VALUE;
        int minFirst = Integer.MAX_VALUE, minSecond = Integer.MAX_VALUE;

        for(int i = 0; i < nums.length; i++){

            if(nums[i] >= first){
                third = second;
                second = first;
                first = nums[i];
            }

            else if(nums[i] >= second){
                third = second;
                second = nums[i];
            }

            else if(nums[i] >= third){
                third = nums[i];
            }

            if(nums[i] <= minFirst){
                minSecond = minFirst;
                minFirst = nums[i];
            }

            else if(nums[i] <= minSecond)
                minSecond = nums[i];
        }

        return Math.max(first * second * third, first * minSecond * minFirst);
    }
}
