class Solution {
    public int stoneGameVI(int[] aliceValues, int[] bobValues) {
        int n = aliceValues.length;
        int diff = 0; // Sum of Bob's values

        for (int i = 0; i < n; i++) {
            aliceValues[i] += bobValues[i];
            diff -= bobValues[i];
        }

        // Now aliceValues stores (Alice Value + Bob Value),
        // so sort greedily based on the total importance.
        Arrays.sort(aliceValues);

        // Since the largest values are at the end after sorting,
        // Alice picks the largest remaining stone first, then every alternate stone.
        for (int i = n - 1; i >= 0; i -= 2) {
            // After this loop:
            // diff = Alice's total score - Bob's total score
            diff += aliceValues[i];
        }

        return Integer.compare(diff, 0);
    }
}
