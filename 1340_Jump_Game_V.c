int dfs(int* arr, int arrSize, int d, int idx, int* dp){

    // If already computed, return stored value from DP
    if(dp[idx] != 0)
        return dp[idx];

    // Minimum visit count is current index itself
    int maxVisit = 1;

    // Check right side
    for(int i = idx + 1; i <= idx + d && i < arrSize; i++){

        // Can't jump further if greater/equal element appears
        if(arr[i] >= arr[idx])
            break;

        // Current index + best path from next index
        int jumps = 1 + dfs(arr, arrSize, d, i, dp);

        if(jumps > maxVisit)
            maxVisit = jumps;
    }

    // Check left side
    for(int i = idx - 1; i >= idx - d && i >= 0; i--){

        // Can't jump further if greater/equal element appears
        if(arr[i] >= arr[idx])
            break;

        // Current index + best path from next index
        int jumps = 1 + dfs(arr, arrSize, d, i, dp);

        if(jumps > maxVisit)
            maxVisit = jumps;
    }

    // Store result in DP
    dp[idx] = maxVisit;

    return dp[idx];
}

int maxJumps(int* arr, int arrSize, int d) {

    // DP + DFS
    int dp[arrSize];

    for(int i = 0; i < arrSize; i++)
        dp[i] = 0;

    int ans = 1;

    // Try starting from every index
    for(int i = 0; i < arrSize; i++){

        int result = dfs(arr, arrSize, d, i, dp);

        // Update final answer
        if(result > ans)
            ans = result;
    }

    return ans;
}
