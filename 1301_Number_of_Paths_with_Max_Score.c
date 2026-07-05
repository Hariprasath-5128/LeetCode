#define MOD 1000000007

int max(int a, int b) {
    return a > b ? a : b;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pathsWithMaxScore(char ** board, int boardSize, int* returnSize){
    //Can this cell (i,j) be reached from a cell that is below, to the right, or down-right? - dpScore[i][j]

    int n = boardSize;

    //dpScore[i][j] = maximum score to reach this cell ; if you are at cell (i,j) -> with these action we can find which direction is that. [bottom, bottom-right, right]
    int dpScore[101][101];

    //dpWays[i][j] = number of ways to obtain dpScore[i][j]
    long long dpWays[101][101];

    //Initialize
    for(int i = 0; i<n; i++){
        for(int j = 0; j <n; j++){
            dpScore[i][j] = -1;
            dpWays[i][j] = 0;
        }
    }

    //Starting point (S)
    dpScore[n-1][n-1] = 0;
    dpWays[n-1][n-1] = 1;

    // Process from bottom-right towards top-left
    for(int i = n -1 ; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){

            if(board[i][j] == 'X')
                continue;

            if(i == n-1 && j == n-1)
                continue; // Skip S

            int best = -1;
            long long ways = 0;

            //From bottom
            if(i+1 < n && dpScore[i+1][j] != -1)
                best = max(best, dpScore[i+1][j]);

            //From right
            if(j+1 < n && dpScore[i][j+1] != -1)
                best = max(best, dpScore[i][j+1]);

            //From bottom-right (diagonal)
            if(i+1 < n && j+1 < n && dpScore[i+1][j+1] != -1)
                best = max(best, dpScore[i+1][j+1]);

            if(best == -1)
                continue;

            // Count ways from all the directions having the maximum score

            //From bottom
            if(i+1 < n && dpScore[i+1][j] == best)
                ways = (ways + dpWays[i+1][j]) % MOD;

            //From right
            if(j+1 < n && dpScore[i][j+1] == best)
                ways = (ways + dpWays[i][j+1]) % MOD;

            //From bottom-right (diagonal)
            if(i+1 < n && j+1 < n && dpScore[i+1][j+1] == best)
                ways = (ways + dpWays[i+1][j+1]) % MOD;

            int val = 0; //Consider the current cell (i,j)

            if(board[i][j] >= '1' && board[i][j] <= '9')
                val = board[i][j] - '0';

            dpScore[i][j] = best + val;
            dpWays[i][j] = ways;
        }
    }

    int *ans = malloc(sizeof(int) * 2);
    *returnSize = 2;

    if(dpWays[0][0] == 0) {
        ans[0] = 0;
        ans[1] = 0;
    }
    else {
        ans[0] = dpScore[0][0];
        ans[1] = dpWays[0][0];
    }

    return ans;
}