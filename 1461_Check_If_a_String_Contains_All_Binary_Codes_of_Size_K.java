class Solution {
    public boolean hasAllCodes(String s, int k) {

        //Rolling window
        int total = 1 << k;
        int[] map = new int[total];
        int ans = 0;

        for(int i = 0; i <= s.length() - k; i++){
            int windowNum = Integer.parseInt(s.substring(i, i+k), 2);

            if(map[windowNum] == 0){
                map[windowNum] = 1;
                ans++;
            }
        }

        return total == ans;
    }
}
