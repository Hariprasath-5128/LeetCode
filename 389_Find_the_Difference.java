class Solution {
    public char findTheDifference(String s, String t) {
        int temp = 0;

        for (char i : s.toCharArray()) {
            temp ^= i;
        }
        for (char j : t.toCharArray()) {
            temp ^= j;
        }

        return (char) temp;
    }
}
