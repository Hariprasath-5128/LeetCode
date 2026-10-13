class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;
        for(int i = 0; i < n; i++){
            nums[i] = nums[i] * nums[i];
        }
        Arrays.sort(nums);

        int mid = 0;
        if(n % 2 != 0)
            mid = (int) Math.ceil(n/2.0) - 1;
        else
            mid = n/2;

        long result = 0;
        //System.out.println(n/2);

        for(int i = 0; i < n; i++){
            if(i >= mid){
                result += nums[i];
            }
            else{
                result -= nums[i];
            }
        }

        return result;
    }
}