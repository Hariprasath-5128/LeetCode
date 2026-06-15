int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 * Note: Both returned array and *columnSizes array must be malloced.
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {

    qsort(arr, arrSize, sizeof(int), compare);

    int minDiff = INT_MAX;

    // Find minimum difference
    for(int i = 1; i < arrSize; i++) {
        if(arr[i] - arr[i - 1] < minDiff) {
            minDiff = arr[i] - arr[i - 1];
        }
    }

    int count = 0;

    // Count pairs having minimum difference
    for(int i = 1; i < arrSize; i++) {
        if(arr[i] - arr[i - 1] == minDiff) {
            count++;
        }
    }

    int **ans = malloc(count * sizeof(int *));
    *returnColumnSizes = malloc(count * sizeof(int));//says how many elements in each row 

    int idx = 0;

    // Store pairs
    for(int i = 1; i < arrSize; i++) {
        if(arr[i] - arr[i - 1] == minDiff) {

            ans[idx] = malloc(2 * sizeof(int));

            ans[idx][0] = arr[i - 1];
            ans[idx][1] = arr[i];

            (*returnColumnSizes)[idx] = 2;

            idx++;
        }
    }

    *returnSize = count;

    return ans;
}
