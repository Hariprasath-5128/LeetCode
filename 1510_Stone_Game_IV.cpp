class Solution {
public:
bool winnerSquareGame(int n) {
vector dp(n + 1, false);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (!dp[i - j * j]) {//i-j*j are the previous moves - if previous moves are false means we can't reduce the stones (i-j*j)
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}
};
