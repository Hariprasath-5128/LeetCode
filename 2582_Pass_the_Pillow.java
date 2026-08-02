class Solution {
    public int passThePillow(int n, int time) {

        int cycle = 2 * (n - 1);
        time %= cycle;

        return n-((time-(n-1)) >= 0 ? (time-(n-1)): -(time-(n-1)));
    }
}