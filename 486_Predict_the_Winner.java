class Solution {
    public boolean predictTheWinner(int[] A) {

        /*
        * If the array length is even, Player 1 can always win (or tie).
        * Compute the sums of elements at even and odd indices.
        * Choose the parity with the larger sum, and by selecting the
        * appropriate end on each turn, Player 1 can force picking only
        * elements from that chosen parity throughout the game.
        */

        int n = A.length;
        if ((n & 1) == 0) return true;

        int[][] dp = new int[n][n];
        for (int[] r : dp) 
            Arrays.fill(r, -1);

        //As we have started from the player 1, we can consider the (player 1 - player 2) >= 0
        return maxDiff(0, n - 1, A, dp) >= 0;
    }

    private int maxDiff(int i, int j, int[] A, int[][] dp) {
        if (dp[i][j] != -1) return dp[i][j];        
        if (i == j) return dp[i][j] = A[i];

        // Current player - old player
        return dp[i][j] = Math.max(
            A[i] - maxDiff(i + 1, j, A, dp),
            A[j] - maxDiff(i, j - 1, A, dp)
        );
    }
}
