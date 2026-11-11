class Solution {
    public int minCostClimbingStairs(int[] cost) {
        // Using DP
        int n = cost.length;
        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            if (i < 2) { // Starts at either 0 or 1
                dp[i] = cost[i];
                continue;
            }
            dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
        }

        return Math.min(dp[n - 1], dp[n - 2]);
    }
}
