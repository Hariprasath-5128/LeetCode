/*
LeetCode 693. Binary Number with Alternating Bits

Approach:
1. Extract the least significant bit (LSB) and store it as the previous bit.
2. Right shift the number to process the next bit.
3. Compare the current bit with the previous bit.
4. If two adjacent bits are the same, return false.
5. If all adjacent bits alternate, return true.

Time Complexity: O(number of bits) ≈ O(32) = O(1)
Space Complexity: O(1)
*/

class Solution {
    public boolean hasAlternatingBits(int n) {
        // Store the least significant bit
        int prev = n & 1;

        // Remove the processed bit
        n >>= 1;

        // Traverse remaining bits
        while (n > 0) {
            int curr = n & 1;

            // Adjacent bits must be different
            if (curr == prev)
                return false;

            prev = curr;
            n >>= 1;
        }

        return true;
    }
}
