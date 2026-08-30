class Solution {
    public int minimumDeletions(int[] nums) {
        int minPos = -1;
        int maxPos = -1;
        int min = 1000000;
        int max = -1000000;

        if(nums.length == 1|| nums.length == 2)
            return nums.length;

        int n = nums.length;
        
        for(int i = 0; i < nums.length; i++){
            if(min > nums[i]){
                min = nums[i];
                minPos = i;
            }
            if(max < nums[i]){
                max = nums[i];
                maxPos = i;
            }
        }

        int ans1 = -1, ans2 = -1, ans3 = -1;
        ans1 = Math.min(minPos + 1 + (n - maxPos), maxPos + 1 + (n - minPos));

        ans2 = Math.max(minPos + 1, maxPos + 1);

        ans3 = Math.max(n - minPos, n - maxPos);

        int ans = Math.min(ans3, Math.min(ans1, ans2));
        return ans;
    }
}
