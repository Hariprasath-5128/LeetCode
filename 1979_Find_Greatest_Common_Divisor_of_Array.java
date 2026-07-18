class Solution {

    // A common method for computing the greatest common divisor gcd(a,b)
    // of two integers is the Euclidean algorithm.
    // Key recurrence: gcd(a, b) = gcd(b, a % b)
    public int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public int findGCD(int[] nums) {
        int mx = Integer.MIN_VALUE;
        int mn = Integer.MAX_VALUE;

        for (int num : nums) {
            mn = Math.min(mn, num);
            mx = Math.max(mx, num);
        }

        return gcd(mx, mn);
    }
}
