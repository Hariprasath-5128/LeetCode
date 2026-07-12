class Solution {
    public int maxFrequency(int[] nums, int k) {
        //Using sliding window

        Arrays.sort(nums);
        int ans = 0;
        int left = 0;
        int right = 0;
        long curr = 0;

        for(right = 0; right < nums.length; right++){
            long target = nums[right];
            curr += target;

            while((right - left + 1) * target - curr > k){
                curr -= nums[left];
                left++;
            }

            ans = Math.max(ans, (right - left + 1));
        }

        return ans;
    }
}
