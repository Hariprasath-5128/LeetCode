/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int m = gridSize; 
    int n = gridColSize[0];

    int **ans = (int **)malloc(sizeof(int *) * m);
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);

    for(int i = 0; i < m; i++){
        ans[i] = (int *)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        memcpy(ans[i], grid[i], sizeof(int) * n);
    }

    int layers = (m < n ? m:n) / 2;

    for(int layer = 0; layer < layers; layer++){

        int top = layer;
        int left = layer;
        int bottom = m - layer -1;
        int right = n - layer -1;

        int len = 2 *(bottom - top + right - left);
        int *arr = (int *)malloc(sizeof(int) * len);

        int idx = 0;

        //top -> bottom (left column)
        for(int i = top; i <= bottom; i++)
            arr[idx++] = grid[i][left];

        //left + 1 -> right (bottom row)
        for(int j = left + 1; j <= right; j++)
            arr[idx++] = grid[bottom][j];

        //bottom - 1 -> top (right column)
        for(int i = bottom - 1; i >= top; i--)
            arr[idx++] = grid[i][right];

        //right - 1 -> left + 1 (top row)
        for(int j = right - 1; j > left; j--)
            arr[idx++] = grid[top][j];

        int shift = k % len;
        idx = 0;

        //top -> bottom (left column)
        for(int i = top; i <= bottom; i++){
            ans[i][left] = arr[(idx + len - shift) % len];
            idx++;
        }

        //left + 1 -> right (bottom row)
        for(int j = left + 1; j <= right; j++){
            ans[bottom][j] = arr[(idx + len - shift) % len];
            idx++;
        }

        //bottom - 1 -> top (right column)
        for(int i = bottom - 1; i >= top; i--){
            ans[i][right] = arr[(idx + len - shift) % len];
            idx++;
        }

        //right - 1 -> left + 1 (top row)
        for(int j = right - 1; j > left; j--){
            ans[top][j] = arr[(idx + len - shift) % len];
            idx++;
        }

        free(arr);
    }

    *returnSize = m;
    return ans;
}