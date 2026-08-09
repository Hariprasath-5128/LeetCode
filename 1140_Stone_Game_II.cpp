class Solution {
public:
    int dp[2][101][101];

    int solve(vector<int>& piles, int turn, int i, int m) {
        int n = piles.size();

        if (i == n)
            return 0;

        if (dp[turn][i][m] != -1)
            return dp[turn][i][m];

        int res = (turn == 0) ? 0 : INT_MAX;
        int score = 0;

        for (int x = 1; x <= min(2 * m, n - i); x++) {
            score += piles[i + x - 1];

            // Alice maximizes Alice's score
            if (turn == 0)
                res = max(res, score + solve(piles, 1, i + x, max(m, x)));
            // Bob minimizes Alice's score
            else
                res = min(res, solve(piles, 0, i + x, max(m, x)));
        }

        return dp[turn][i][m] = res;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, 0, 1);
    }
};