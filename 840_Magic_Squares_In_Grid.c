#include <stdbool.h>

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {

    int count = 0;

    if(gridSize < 3 || gridColSize[0] < 3)
        return 0;

    for(int r = 0; r < gridSize - 2; r++) {

        for(int c = 0; c < gridColSize[0] - 2; c++) {

            // Optional optimization
            if(grid[r+1][c+1] != 5)
                continue;

            // Check distinct numbers from 1 to 9
            bool valid = true;

            int distinct[10] = {0};

            for(int i = 0; i < 3; i++) {

                for(int j = 0; j < 3; j++) {

                    int val = grid[r+i][c+j];

                    // Range check
                    if(val < 1 || val > 9) {
                        valid = false;
                        break;
                    }

                    // Duplicate check
                    if(distinct[val]) {
                        valid = false;
                        break;
                    }

                    distinct[val] = 1;
                }

                if(!valid)
                    break;
            }

            if(!valid)
                continue;

            int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

            bool rsum = false;
            bool csum = false;
            bool dsum = false;

            // Row sums
            if((grid[r][c] + grid[r][c+1] + grid[r][c+2] == sum) &&

               (grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] == sum) &&

               (grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2] == sum)) {

                rsum = true;
            }

            // Column sums
            if((grid[r][c] + grid[r+1][c] + grid[r+2][c] == sum) &&

               (grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1] == sum) &&

               (grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2] == sum)) {

                csum = true;
            }

            // Diagonal sums
            if((grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] == sum) &&

               (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] == sum)) {

                dsum = true;
            }

            if(rsum && csum && dsum)
                count++;
        }
    }

    return count;
}
