class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {

        const int MAX = 200;
        //dp[g1][g2] = number of ways to obtain gcd(seq1) = g1 and gcd(seq2) = g2

        vector<vector<long long>> dp(MAX + 1, vector<long long>(MAX + 1, 0));

        //Initialising the both subsequences are as empty
        dp[0][0] = 1;

        /*

        1. Ignore the current element
            - Do not put it in either subsequence.
            - Current GCDs remain unchanged.
            - State: (g1, g2)

        2. Put the current element into seq1
            - Update the GCD of seq1.
            - New GCD:
                if g1 == 0 → new_g1 = nums[i]
                else → new_g1 = gcd(g1, nums[i])
            - State: (new_g1, g2)

        3. Put the current element into seq2
            - Update the GCD of seq2.
            - New GCD:
                if g2 == 0 → new_g2 = nums[i]
                else → new_g2 = gcd(g2, nums[i])
            - State: (g1, new_g2)

        */

        for(int x : nums){
            //Check for all the gcd states
            vector<vector<long long>>ndp = dp; 

            for(int g1 = 0; g1 <= MAX; g1++){
                for(int g2 = 0; g2 <= MAX; g2++){

                    if(dp[g1][g2]==0) //this state is not possible till now
                        continue;

                    long long ways = dp[g1][g2];

                    //Put x into seq1
                    int ng1 = (g1 == 0) ? x : gcd(g1, x);

                    ndp[ng1][g2] = (ndp[ng1][g2] + ways) % MOD;

                    // Put x into seq 2
                    int ng2=(g2==0)?x:gcd(g2,x);

                    ndp[g1][ng2]=(ndp[g1][ng2]+ways)%MOD;

                }
            }
            dp.swap(ndp);
        }

        long long ans = 0;

        //same gcd in both subsequences
        for(int g = 1 ; g <= MAX; g++){
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};
