class Solution {
    public int reverseDegree(String s) {
        int ans = 0;
        int i = 1;
        for(char c: s.toCharArray()){
            ans += (26-(c-'a')) * i;
            i++;
        }

        return ans;
    }
}