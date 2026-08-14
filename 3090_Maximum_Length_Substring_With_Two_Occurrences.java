class Solution {
    public int maximumLengthSubstring(String s) {
        int[] freq = new int[26];
        Arrays.fill(freq, 0);

        int ptr = 0;
        int n = s.length();
        int max = 0;

        for(int i = 0; i < n; i++){
            char c = s.charAt(i);
            freq[c - 'a']++;

            while(freq[c - 'a'] > 2){
                char ptrC = s.charAt(ptr);
                freq[ptrC - 'a']--;
                ptr++;
            }

            max = Math.max(max, i - ptr +1); 
        }

        return max;
    }
}