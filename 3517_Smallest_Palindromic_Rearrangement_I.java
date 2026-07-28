class Solution {
    public String smallestPalindrome(String s) {
        int[] freq = new int[26];

        for(int i = 0; i < s.length(); i++){
            freq[s.charAt(i)-'a']++;    
        }

        StringBuilder firstHalf = new StringBuilder();
        char middle = 0;

        // Build first half and find middle character
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = (char) ('a' + i);
            }

            for (int j = 0; j < freq[i] / 2; j++) {
                firstHalf.append((char) ('a' + i));
            }
        }

        String secondHalf = new StringBuilder(firstHalf).reverse().toString();

        if (middle != 0) {
            return firstHalf.toString() + middle + secondHalf;
        }

        return firstHalf.toString() + secondHalf;
    }
}
