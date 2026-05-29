bool dfs(int r, int c, int row, int col, int** grid, bool** visited){
    if(r<0 || r>=row || c<0 || c>=col)
        return false;

    if(grid[r][c] == 1 || visited[r][c]==1)
        return false;

    if(row-1 == r)
        return true;

    visited[r][c] = true;

    return dfs(r+1, c, row, col, grid, visited) || dfs(r-1, c, row, col, grid, visited) || dfs(r, c+1, row, col, grid, visited) || dfs(r, c-1, row, col, grid, visited);
}

bool canCross(int row, int col, int** cells, int day){
    int** grid = (int**)malloc(row * sizeof(int*));
    bool** visited = (bool**)malloc(row * sizeof(bool*));

    for(int i = 0; i < row; i++) {
        grid[i] = (int*)calloc(col, sizeof(int));
        visited[i] = (bool*)calloc(col, sizeof(bool));
    }

    for(int i = 0; i<day; i++){
        int r = cells[i][0]-1;
        int c = cells[i][1]-1;
        grid[r][c] = 1;
    }
    
    bool possible = false;
    
    for(int c = 0; c<col; c++){
        if(grid[0][c] == 0){
            if(dfs(0,c,row,col,grid,visited)){
                possible = true;
                break;
            }
        }
    }

    for(int i = 0; i < row; i++) {
        free(grid[i]);
        free(visited[i]);
    }

    free(grid);
    free(visited);

    return possible;
}

int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize) {
    int low = 1;
    int high = cellsSize;
    int ans = 0;

    // Let n = row*col
    // Generally, the answer will be between 1 to n - row / n-col
    // Instead of using the linear search from 1 to n-row, check with binary search
    // If the mid (days -> count) is now can't be reached, then after the mid also can't be reached

    while(low<=high){
        int mid = low + (high - low)/2;
        
        if(canCross(row, col, cells, mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
