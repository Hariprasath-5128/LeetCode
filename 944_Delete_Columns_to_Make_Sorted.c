#include <string.h>

int minDeletionSize(char** strs, int strsSize) {

    int cols = strlen(strs[0]);
    int deleteCount = 0;

    for(int i = 0; i < cols; i++) {

        for(int j = 0; j < strsSize - 1; j++) {

            if(strs[j][i] > strs[j + 1][i]) {
                deleteCount++;
                break;
            }
        }
    }

    return deleteCount;
}
