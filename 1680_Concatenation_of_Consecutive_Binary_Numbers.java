class Solution {
    public int concatenatedBinary(int n) {
        int MOD = 1_000_000_007;

        //Do it with Bit manipulation
        long  ans = 0;

        //The number of bits increases only when we reach a power of 2.
        int bits = 0;

        for(int i = 1; i <= n; i++){
            if((i & (i-1)) == 0)
                bits++;

            ans = ((ans << bits) + i) % MOD;

        }
        return (int) (ans);
    }
}