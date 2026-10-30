class Solution {
    public boolean isSubsequence(String s, String t) {
        int ptr = 0;
        int n1 = s.length();

        for (char i : t.toCharArray()) {
            if (ptr == n1) {
                return true;
            }

            char j = s.charAt(ptr);

            if (j == i) {
                ptr++;
            }
        }

        return ptr == n1;
    }
}