class Solution {
    public int binaryGap(int n) {
        int[] arr = new int[32];

        int t = 0;
        for(int i = 0; i < 32; i++){
            if(((n >> i) & 1) != 0)
                arr[t++] = i;
        }

        int ans = 0;
        for(int i = 0; i < t-1; i++){
            ans = Math.max(ans, arr[i+1] - arr[i]);
        }

        return ans;
    }
}
