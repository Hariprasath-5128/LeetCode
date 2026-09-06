class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();

        //dp[i][j] = minimum operations to convert first i chars of s1 → first j chars of s2.
        int[][] dp = new int[m + 1][n + 1];

        for(int i = 0; i <= m; i++)
            dp[i][0] = i;

        for(int i = 0; i <= n; i++)
            dp[0][i] = i;

        /*
        dp[i][j-1]   → INSERT s2[j-1]
        dp[i-1][j]   → DELETE s1[i-1]
        dp[i-1][j-1] → REPLACE s1[i-1] with s2[j-1]
         */

        //conceptually, all edit operations are performed on s1 to transform it into s2.
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1.charAt(i-1) == word2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }

                else{
                    dp[i][j] = Math.min(Math.min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
}
