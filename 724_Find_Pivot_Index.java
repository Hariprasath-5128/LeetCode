class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        int j = 0;
        prefixSum[0] = 0;

        for(int i = 0; i < n; i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }


        for(int i = 0; i < prefixSum.length - 1; i++){
            int left = prefixSum[i];
            int right = prefixSum[prefixSum.length - 1] - prefixSum[i + 1];

            if(left == right)
                return i;
        }

        return -1;
    }
}
