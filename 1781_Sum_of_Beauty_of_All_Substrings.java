class Solution {
    public int beautySum(String s) {
        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            int[] freq = new int[26];
            int c = s.charAt(i) - 'a';
            freq[c]++;

            for(int j = i+1; j < s.length(); j++){
                int t = s.charAt(j) - 'a';
                freq[t]++;
                
                int min = Integer.MAX_VALUE;
                int max = Integer.MIN_VALUE;

                for(int k = 0; k < 26; k++){
                    if (freq[k] > 0) {
                        min = Math.min(min, freq[k]);
                        max = Math.max(max, freq[k]);
                    }
                }

                ans += (max - min);
            }
        }

        return ans;
    }
}