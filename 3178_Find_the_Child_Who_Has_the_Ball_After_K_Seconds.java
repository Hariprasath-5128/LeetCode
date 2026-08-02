class Solution {
    public int numberOfChild(int n, int k) {
        int cycle = 2 * (n - 1);
        int time = k;
        time %= cycle;

        return n-((time-(n-1)) >= 0 ? (time-(n-1)): -(time-(n-1)))-1;
    }
}
