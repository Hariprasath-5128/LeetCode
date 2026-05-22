int max(int a, int b){
    return (a > b) ? a : b;
}

int maximumJumps(int* nums, int numsSize, int target) {

    // DP approach
    // dp[i] = maximum number of jumps to reach index i

    int dp[numsSize];

    for(int i = 0; i < numsSize; i++){
        dp[i] = -1;
    }

    // Already at index 0
    dp[0] = 0;

    for(int j = 0; j < numsSize; j++){

        // Skip unreachable indices
        if(dp[j] == -1){
            continue;
        }

        for(int i = j + 1; i < numsSize; i++){

            // Valid jump
            if(abs(nums[i] - nums[j]) <= target){

                // Update maximum jumps
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[numsSize - 1];
}
