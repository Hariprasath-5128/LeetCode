class Solution {
    public int countPrimeSetBits(int left, int right) {

        int ans = 0;

        for (int i = left; i <= right; i++) {
            int bitCount = Integer.bitCount(i);
            if (bitCount == 2 || bitCount == 3 || bitCount == 5 || bitCount == 7 ||
                bitCount == 11 || bitCount == 13 || bitCount == 17 || bitCount == 19 ||
                bitCount == 23 || bitCount == 29 || bitCount == 31)
                ans++;
        }

        return ans;
    }
}
