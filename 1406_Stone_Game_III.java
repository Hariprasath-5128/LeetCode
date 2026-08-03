class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;

        // dp[i] = Maximum score difference (Current Player - Opponent)
        // that the current player can achieve starting from index i.
        int[] dp = new int[n + 1];

        // Base case:
        // dp[n] = 0 because no stones are left to pick.
        Arrays.fill(dp, 0);

        // Build the answer from the end towards the beginning.
        for (int i = n - 1; i >= 0; i--) {

            int sum = 0;

            // Initialize with the smallest possible value since
            // we are looking for the maximum score difference.
            dp[i] = Integer.MIN_VALUE;

            // Current player can take 1, 2, or 3 stones.
            for (int j = i; j < Math.min(n, i + 3); j++) {

                // Sum of stones picked from i to j.
                sum += stoneValue[j];

                // After taking these stones, the opponent starts from j + 1.
                // dp[j + 1] represents the opponent's best score difference.
                //
                // Current player's advantage:
                // = Stones collected now - Opponent's future advantage
                dp[i] = Math.max(dp[i], sum - dp[j + 1]);
            }
        }

        // Positive  -> Alice gets a higher score.
        // Negative  -> Bob gets a higher score.
        // Zero      -> Both end with the same score.
        if (dp[0] == 0)
            return "Tie";
        else if (dp[0] > 0)
            return "Alice";
        else
            return "Bob";
    }
}
