#include <stdlib.h>
#include <limits.h>

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    // negCount = number of negative elements
    // Even negatives  -> answer = sum of absolute values
    // Odd negatives   -> answer = sum of absolute values - 2 * minimum absolute value

    int col = *matrixColSize;

    int negCount = 0;
    long minValue = INT_MAX;
    long long sum = 0;  // CHANGED: use long long to avoid overflow

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < col; j++) {

            sum += abs(matrix[i][j]);

            if (matrix[i][j] < 0)
                negCount++;

            // CHANGED: track minimum ABSOLUTE value, not minimum value
            if (abs(matrix[i][j]) < minValue)
                minValue = abs(matrix[i][j]);
        }
    }

    if (negCount % 2 == 0)
        return sum;

    return sum - 2LL * minValue; // CHANGED: use minimum absolute value
}
