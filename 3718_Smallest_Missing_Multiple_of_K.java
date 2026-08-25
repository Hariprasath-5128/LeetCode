class Solution {
    public int missingMultiple(int[] nums, int k) {
        int[] freq = new int[101];
        Arrays.fill(freq, 0);

        for(int i = 0; i  < nums.length; i++){
            freq[nums[i]]++;
        }

        int res = -1;
        int i;
        for(i = k; i <= 100; i+=k){
            if(freq[i] == 0){
                res = i;
                break;
            }
        }
        if(res == -1 && i > 100) return i;
        return res;
    }
}