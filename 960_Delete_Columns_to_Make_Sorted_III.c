int minDeletionSize(char** strs, int strsSize) {

    // Number of columns
    int m = strlen(strs[0]);

    // dp[j] = longest valid subsequence ending at column j
    int dp[m];

    // Stores maximum columns we can keep
    int maxKeep = 1;

    // Every single column alone is valid
    for(int i = 0; i < m; i++) {
        dp[i] = 1;
    }

    // Try building subsequences ending at column j
    for(int j = 0; j < m; j++) {

        // Check all previous columns
        for(int i = 0; i < j; i++) {

            // Assume column i can come before j
            bool valid = true;

            // Verify for every string
            for(int k = 0; k < strsSize; k++) {

                // If any row becomes decreasing,
                // then i -> j is invalid
                if(strs[k][i] > strs[k][j]) {
                    valid = false;
                    break;
                }
            }

            // If valid, apply LIS transition
            if(valid) {

                // Extend previous valid subsequence
                if(dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                }
            }
        }

        // Track overall maximum kept columns
        if(dp[j] > maxKeep) {
            maxKeep = dp[j];
        }
    }

    // Minimum deletions = total columns - kept columns
    return m - maxKeep;
}
