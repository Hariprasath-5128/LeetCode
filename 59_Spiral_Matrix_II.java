class Solution {
    public int[][] generateMatrix(int n) {
        // Create the empty n x n matrix
        int[][] matrix = new int[n][n];
        
        if (n == 0) {
            return matrix;
        }

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        
        int num = 1;         // The number we are inserting
        int total = n * n;   // The final number to insert

        while (num <= total) {
            // Traverse from left to right across the top
            for (int i = left; i <= right && num <= total; i++) {
                matrix[top][i] = num++;
            }
            top++;

            // Traverse downwards down the right side
            for (int j = top; j <= bottom && num <= total; j++) {
                matrix[j][right] = num++;
            }
            right--;

            // Traverse from right to left across the bottom
            for (int l = right; l >= left && num <= total; l--) {
                matrix[bottom][l] = num++;
            }
            bottom--;

            // Traverse upwards up the left side
            for (int m = bottom; m >= top && num <= total; m--) {
                matrix[m][left] = num++;
            }
            left++;
        }

        return matrix;
    }
}