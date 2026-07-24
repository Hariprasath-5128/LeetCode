class Solution {
    public int uniqueXorTriplets(int[] nums) {
        boolean[] pair = new boolean[2048];
        int n = nums.length;

        /*
         * LeetCode 3514 - Number of Unique XOR Triplets II
         *
         * Pattern:
         * Triplet XOR
         *      ↓
         * (a ^ b) ^ c (Associative Property)
         *      ↓
         * Compute all pair XORs
         *      ↓
         * Store in boolean[2048]
         *      ↓
         * XOR each pair XOR with every array element
         *      ↓
         * Store in boolean[2048]
         *      ↓
         * Count all true values
         *
         * Time Complexity:
         * O(n² + 2048 × n) ≈ O(n²)
         */

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pair[nums[i] ^ nums[j]] = true;
            }
        }

        boolean[] ans = new boolean[2048];

        for (int i = 0; i < 2048; i++) {
            if (!pair[i]) continue;

            for (int num : nums) {
                ans[i ^ num] = true;
            }
        }

        int count = 0;

        for (boolean b : ans) {
            if (b) {
                count++;
            }
        }

        return count;
    }
}
