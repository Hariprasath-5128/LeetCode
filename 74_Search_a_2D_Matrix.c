#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    // Sorted matrix - treat as 1D sorted array
    int low = 0;
    int high = rows * cols - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // Convert 1D index to 2D index
        int r = mid / cols;
        int c = mid % cols;

        if (matrix[r][c] == target) {
            return true;
        }

        else if (matrix[r][c] > target) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return false;
}
