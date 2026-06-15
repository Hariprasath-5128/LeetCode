int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {

    int m = gridSize;
    int n = *gridColSize;

    int row[m][n+1];
    int col[m+1][n];

    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));

    // Row prefix sums
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            row[i][j + 1] = row[i][j] + grid[i][j];
        }
    }

    // Column prefix sums
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            col[i + 1][j] = col[i][j] + grid[i][j];
        }
    }

    int maxSize = (m < n) ? m : n;

    for(int k = maxSize; k>=2; k--){
        for(int r = 0; r+k<=m; r++){
            for(int c = 0; c+k<=n;c++){

                int target = row[r][c+k]-row[r][c];
                int valid = 1;

                // Check rows
                for(int i = r; i<r+k;i++){
                    int sum = row[i][c+k]-row[i][c];
                    if(sum!=target){
                        valid=0;
                        break;
                    }
                }

                if(!valid)
                    continue;

                // Check rows
                for(int j = c; j<c+k;j++){
                    int sum = col[r+k][j]-col[r][j];
                    if(sum!=target){
                        valid=0;
                        break;
                    }
                }

                if(!valid)
                    continue;

                //Main diagonal
                int diag1=0;

                for(int i = 0; i<k;i++){
                    diag1+=grid[r+i][c+i];
                }
                if(diag1!=target)
                    continue;

                //Secondary diagonal
                int diag2=0;

                for(int i = 0; i<k;i++){
                    diag2+=grid[r+i][c+k-1-i];
                }
                if(diag2!=target)
                    continue;
                return k;
            }
        }
    }
    return 1;
}
