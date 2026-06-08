#include <string.h>

int max(int a, int b){
    return a > b ? a : b;
}

int dp[1001][1001];

int LCS(char* s1, char* s2, int i, int j)
{
    if(s1[i]=='\0' || s2[j]=='\0')
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = s1[i] + LCS(s1, s2, i+1, j+1);

    return dp[i][j] = max(LCS(s1, s2, i+1, j), LCS(s1, s2, i, j+1));
}

int minimumDeleteSum(char* s1, char* s2) {
    memset(dp, -1, sizeof(dp));

    int total = 0;

    for(int i = 0; s1[i] != '\0'; i++)
        total += s1[i];

    for(int i = 0; s2[i] != '\0'; i++)
        total += s2[i];

    int commonSum = LCS(s1, s2, 0, 0);

    return total - 2 * commonSum;
}
