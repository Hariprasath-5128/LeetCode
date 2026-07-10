/*
LeetCode 3534. Path Existence Queries in a Graph II

Approach
1. Sort nodes by value while preserving their original indices.
2. Map each original index to its position in the sorted array.
3. Using a sliding window, compute st[i][0]:
   the farthest sorted position reachable from i in one jump.
4. Build the binary lifting table:
   st[i][j] = farthest position reachable from i using 2^j jumps.
5. For each query:
   - Convert original indices to sorted positions.
   - Binary lift greedily to stay just before the destination.
   - If one final jump reaches the destination, return the total jumps;
     otherwise return -1.

Time Complexity:
Sorting          : O(n log n)
Sliding Window   : O(n)
Binary Lifting   : O(n log n)
Queries          : O(q log n)

Overall: O((n + q) log n)
Space: O(n log n)
*/

import java.util.*;

class Solution {
    public int[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {

        int[][] newNums = new int[n][2];
        for (int i = 0; i < n; i++)
            newNums[i] = new int[]{nums[i], i};

        // Sort by value while keeping original indices.
        Arrays.sort(newNums, (a, b) -> a[0] - b[0]);

        // getI[originalIndex] = sorted position
        int[] getI = new int[n];
        for (int i = 0; i < n; i++)
            getI[newNums[i][1]] = i;

        // st[i][j] = farthest sorted position reachable
        // from node i using exactly 2^j jumps.
        int[][] st = new int[n][18];

        // Sliding window right pointer.
        int r = 0;

        for (int i = 0; i < n; i++) {
            if (r < i)
                r = i;

            // Expand while:
            // 1. consecutive nodes stay connected.
            // 2. entire window is reachable from i in one jump.
            while (r + 1 < n &&
                   newNums[r + 1][0] - newNums[r][0] <= maxDiff &&
                   newNums[r + 1][0] - newNums[i][0] <= maxDiff)
                r++;

            // Base case: one jump.
            st[i][0] = r;
        }

        // Binary lifting preprocessing.
        for (int j = 1; j < 18; j++)
            for (int i = 0; i < n; i++)
                st[i][j] = st[st[i][j - 1]][j - 1];

        int[] ans = new int[queries.length];

        for (int i = 0; i < queries.length; i++) {

            // Convert original indices to sorted positions.
            int a = getI[queries[i][0]];
            int b = getI[queries[i][1]];

            if (a > b) {
                int t = a;
                a = b;
                b = t;
            }

            if (a == b) {
                ans[i] = 0;
                continue;
            }

            int curr = a;
            int steps = 0;

            // Take the largest possible jumps while staying before b.
            for (int j = 17; j >= 0; j--) {
                if (st[curr][j] < b) {
                    curr = st[curr][j];
                    steps += (1 << j);
                }
            }

            // One final jump if possible.
            ans[i] = (st[curr][0] >= b) ? steps + 1 : -1;
        }

        return ans;
    }
}
