#include <stdbool.h>
#include <string.h>

bool canReach(char* s, int minJump, int maxJump) {
    int n = strlen(s);

    //DP+Sliding window 

    //dp[i] = can we reach index i
    bool dp[n];
    for(int i = 0; i<n; i++){
        dp[i] = false;
    }
    dp[0] = true; //Starting index

    //reachable - number of reachable index inside the current sliding window at i'th position
    int reachable = 0;

    for(int i = 1; i<n; i++){
        // Nex entering index; Window :[i-maxJump , i-minJump]
        //Right side-enter: i-minJump

        if(i-minJump >=0 && dp[i-minJump]){
            reachable++;
        }

        //Old leaving index
        //Left side leaves: i - maxJump - 1
        if(i-maxJump-1 >=0 && dp[i-maxJump-1]){
            reachable--;
        }

        //Current index - i if reachable:
        //atleast from the current window it should be reachable
        if(s[i]=='0' && reachable > 0){
            dp[i] = true;
        }
    }
    return dp[n-1];
}
