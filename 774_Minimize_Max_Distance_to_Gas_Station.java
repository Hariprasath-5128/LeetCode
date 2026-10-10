class Solution {
    public double minimiseMaxDistance(int[] arr, int k) {
        int n = arr.length;
        double[] gap = new double[n - 1];
        double low = 0;
        double high = 0;

        for (int i = 1; i < n; i++) {
            gap[i - 1] = arr[i] - arr[i - 1];
            high = Math.max(high, gap[i - 1]);
        }

        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0;

            int k_used = 0;
            for (double j : gap) {
                k_used += (int) (Math.ceil(j / mid) - 1);

                if (k_used > k)
                    break;
            }

            if (k_used > k) {
                low = mid; // We can't add low = mid + 1 because the update step can't be 1.
            } else {
                high = mid; // This converges toward the smallest feasible maximum distance.
            }
        }

        return high; // high maintains a feasible answer.
    }
}