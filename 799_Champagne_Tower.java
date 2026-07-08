class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {

        double[][] arr = new double[102][102]; //100 rows are there

        arr[0][0] = poured; //1st cup already poured

        for(int r = 0; r < query_row; r++){
            for(int c = 0; c <= r; c++){

                double x = arr[r][c]; 
                double q = (x - 1.0)/2; //These are the quantity that will go to the next row (OVERFLOW)

                if(q <= 0)
                    continue;

                arr[r+1][c] += q;
                arr[r+1][c+1] += q;
            }
        }

        return Math.min(1, arr[query_row][query_glass]);
    }
}
