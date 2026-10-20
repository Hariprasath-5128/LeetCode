class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        //Start at the top right cell
        //Go left if target is smaller
        //Go down if target is larger

        //This is the stair-case method : Eliminates one row or column per step

        int r = 0;
        int c = matrix[0].length - 1;

        while(r < matrix.length && c >= 0){
            if(matrix[r][c] == target)
                return true;

            else if(matrix[r][c] > target)
                c--;

            else
                r++;
        }

        return false;
    }
}