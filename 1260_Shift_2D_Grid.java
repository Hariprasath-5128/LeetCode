import java.util.*;

class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {

        int m = grid.length;
        int n = grid[0].length;

        // Convert 2D grid to 1D list
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                list.add(grid[i][j]);
            }
        }

        int size = list.size();
        k %= size;

        // Rotate right using 3 reverses
        reverse(list, 0, size - 1);
        reverse(list, 0, k - 1);
        reverse(list, k, size - 1);

        // Convert back to 2D List
        List<List<Integer>> ans = new ArrayList<>();
        int idx = 0;

        for (int i = 0; i < m; i++) {
            List<Integer> row = new ArrayList<>();

            for (int j = 0; j < n; j++) {
                row.add(list.get(idx));
                idx++;
            }

            ans.add(row);
        }

        return ans;
    }

    private void reverse(List<Integer> list, int left, int right) {
        while (left < right) {
            int temp = list.get(left);
            list.set(left, list.get(right));
            list.set(right, temp);

            left++;
            right--;
        }
    }
}
