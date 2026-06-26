/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes) {

    int col = *boxGridColSize;

    char **rotatedBox = (char **)malloc(col * sizeof(char *));
    for (int i = 0; i < col; i++) {
        rotatedBox[i] = (char *)malloc(boxGridSize * sizeof(char));
    }

    //Rotate the Box
    for(int r = 0; r < boxGridSize; r++){
        for(int c = 0; c < col; c++){
            rotatedBox[c][boxGridSize - 1 - r] = boxGrid[r][c];
        }
    }

    // Gravity (Downwards after rotation)
    for (int j = 0; j < boxGridSize; j++) {

        int emptyPointer = col - 1;
        // Traverse from bottom to top
        for (int i = col - 1; i >= 0; i--) {

            if(rotatedBox[i][j] == '.'){
                if(emptyPointer < i) //If a multiple '.' stacked, it should point at the bottom of '.'
                    emptyPointer = i;
            }

            else if(rotatedBox[i][j] == '*'){
                emptyPointer = i - 1;
            }

            else if(rotatedBox[i][j] == '#'){

                if(i != emptyPointer){ //Not already in the current position
                    rotatedBox[emptyPointer][j] = '#';
                    rotatedBox[i][j] = '.';
                }

                emptyPointer--;
            }
        }
    }
    // Return details
    *returnSize = col;

    *returnColumnSizes = (int *)malloc(col * sizeof(int));
    for (int i = 0; i < col; i++) {
        (*returnColumnSizes)[i] = boxGridSize;
    }

    return rotatedBox;
}
