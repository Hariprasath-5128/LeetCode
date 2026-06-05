typedef long long ll;

typedef struct {
    //If N = 4848, and the current state = 121 _;

    ll count; //Number of the possible states below the current state 
    //count = 10 [0..9 possible state]

    ll sum; //Total waviness of ALL numbers that can be formed below this state.
    //sum = 0 + 0 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 8 (1212 - 1219, wrt the last three digits [3 - window size])
} Node;

Node dp[20][11][11][2];
bool vis[20][11][11][2]; // [len of digit - for safety = 20][possible number -1 to 9 = 11][same as before][started / not started = 2 states]

char digits[20];
int len;

Node dfs(int pos, int prev2, int prev1, int started, int tight){
    if(pos == len){
        Node base = {1,0};
        return base;
    }

    if(!tight && vis[pos][prev2+1][prev1+1][started]){
        return dp[pos][prev2+1][prev1+1][started];
    }

    int limit = tight ? digits[pos] - '0':9;

    Node ans = {0,0};

    for(int d = 0; d<=limit; d++){
        int nextTight = tight && (d==limit);

        if(!started  && d == 0){
            Node nxt = dfs(pos+1, -1, -1, 0, nextTight);
            ans.count += nxt.count;
            ans.sum += nxt.sum;
        }
        else{
            Node nxt;

            if(!started){
                nxt = dfs(pos+1, -1, d, 1, nextTight);
                ans.count += nxt.count;
                ans.sum += nxt.sum;
            }
            else if(prev2 == -1){
                nxt = dfs(pos+1, prev1, d, 1, nextTight);
                ans.count += nxt.count;
                ans.sum += nxt.sum;
            }
            else{
                int add = ((prev1 > prev2 && prev1 > d) ||
                           (prev1 < prev2 && prev1 < d));

                nxt = dfs(pos + 1, prev1, d, 1, nextTight);

                ans.count += nxt.count;
                ans.sum += nxt.sum + (ll)add * nxt.count;
            }
        }
    }

    //if tight = 1, that is like special case -> we can't reuse the computed value
    if(!tight){
        vis[pos][prev2+1][prev1+1][started] = true; //[prev2+1][prev1+1] -> shifting to +1 as it can contain -1 (index as negative ->not possible)
        dp[pos][prev2+1][prev1+1][started] = ans;
    }
    return ans;
}

long long solve(long long n){
    if(n<0) return 0;

    sprintf(digits, "%lld", n); //converting lld to string
    len = strlen(digits);

    memset(vis, 0, sizeof(vis));

    Node res = dfs(0, -1, -1, 0, 1);
    return res.sum;
}

long long totalWaviness(long long num1, long long num2) {
    //Using digit DP 

    //Building as each state - dp[position][prev2][prev1][started][tight]

    //position - current position in DFS
    //prev2, prev1 - 3 window size -> secondLastDigit, LastDigit, currentPossible (using DFS)
    //started - if 0007, started is 1 if it current position is 7 (as its actual number is 7)

    //tight - 0 if it is free to use for 0...9. If N = 484, and pos = 1 with current LastDigit = 1, then it can use the secondLastDigit can use 0....9.
    //tight - 1 if N = 484, and current placed digit is 4 _ _ then the second placable is from 0...8 , where tight = 1.

    //dp is used as for 148_ and if after sliding current window -> ..48_ this state now currently has sum and the count.
    //For next number to find ,for ex: 248_ , it will come to the part -> ..48_ this state now can use the previous dp value instead calculating for ..480 to ..489 again
    
    //solve(num1) - from 0 to num1 -> how many possible waviness

    return solve(num2) - solve(num1-1);
}