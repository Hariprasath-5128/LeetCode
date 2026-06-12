// Hint 1:
// Sort hBars and vBars and consider them separately.
//
// Hint 2:
// Compute the longest sequence of consecutive integer values
// in each array.
//
// Hint 3:
// The maximum square side length is determined by the smaller
// dimension obtained from the horizontal and vertical runs.
//
// Hint 4:
// Square the maximum square side length to get the area.

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int longestConsecutive(int* arr, int size){
    int maxLen = 1;
    int currLen = 1;

    for(int i = 1; i<size; i++){
        if(arr[i] == arr[i-1]+1)
            currLen++;
        else{
            if(currLen > maxLen)
                maxLen = currLen;
            currLen = 1;
        }
    }
    if(currLen > maxLen)
        maxLen = currLen;

    return maxLen;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
    // Can only remove the grid numbers mentioned in hBars and vBars.
    qsort(hBars, hBarsSize, sizeof(int), compare);
    qsort(vBars, vBarsSize, sizeof(int), compare);

    int maxH = longestConsecutive(hBars, hBarsSize) + 1;
    int maxV = longestConsecutive(vBars, vBarsSize) + 1;

    int side = maxH < maxV ? maxH : maxV;

    return side * side;
}
