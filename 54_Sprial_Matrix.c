<<<<<<< HEAD
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];

    *returnSize = rows * cols;
    int* arr = malloc(sizeof(int) * (*returnSize));

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int k = 0, total = (*returnSize);

    while(k < total){

        for(int i = left; i<=right && k < total; i++){
            arr[k++] = matrix[top][i];
        }
        top++;

        for(int j = top; j<=bottom && k < total; j++){
            arr[k++] = matrix[j][right];
        }
        right--;

        for(int l= right; l>=left && k < total; l--){
             arr[k++] = matrix[bottom][l];
        }
        bottom--;

        for(int m = bottom; m>=top && k < total; m--){
            arr[k++] = matrix[m][left];
        }
        left++;

    }
    return arr;
=======
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];

    *returnSize = rows * cols;
    int* arr = malloc(sizeof(int) * (*returnSize));

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int k = 0, total = (*returnSize);

    while(k < total){

        for(int i = left; i<=right && k < total; i++){
            arr[k++] = matrix[top][i];
        }
        top++;

        for(int j = top; j<=bottom && k < total; j++){
            arr[k++] = matrix[j][right];
        }
        right--;

        for(int l= right; l>=left && k < total; l--){
             arr[k++] = matrix[bottom][l];
        }
        bottom--;

        for(int m = bottom; m>=top && k < total; m--){
            arr[k++] = matrix[m][left];
        }
        left++;

    }
    return arr;
>>>>>>> c32e7d35f26fa141d7aecb662d6a8da5e5333b23
}