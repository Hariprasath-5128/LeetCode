class Solution {
    public int longestSubsequence(int[] nums) {
        int len = 0;
        int n = nums.length;

        boolean isAllZero = true;
        int totalXor = 0;

        for(int i = 0; i<n; i++){
            totalXor ^= nums[i];

            if(nums[i] > 0)
                isAllZero = false;

        }

        if(totalXor > 0)
            return n;

        return isAllZero ? 0:n-1;

    }
}