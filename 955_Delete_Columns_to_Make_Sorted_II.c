#include <string.h>

int minDeletionSize(char **strs, int strSize) {

    // GUARD: If there's only 1 string, 0 deletions are needed.
    // This prevents the 'resolved[0]' runtime error.
    if (strSize <= 1) return 0;

    int slen = strlen(strs[0]);
    int reduce = 0;

    // Now strSize - 1 is guaranteed to be at least 1
    int resolved[strSize - 1];

    for (int k = 0; k < strSize - 1; k++) {
        resolved[k] = -1;
    }

    for (int i = 0; i < slen; i++) {

        int column_violated = 0;

        for (int j = 0; j < strSize - 1; j++) {

            // 1. Skip if already resolved by a previous kept column
            if (resolved[j] != -1 && resolved[j] < i) {
                continue;
            }

            // 2. Check for violation (descending order)
            if (strs[j][i] > strs[j + 1][i]) {

                reduce++;

                // Rollback any 'resolved' marks made in THIS column 'i'
                for (int k = 0; k < j; k++) {

                    if (resolved[k] == i) {
                        resolved[k] = -1;
                    }
                }

                column_violated = 1;
                break;
            }

            // 3. Mark as resolved if strictly ascending
            else if (strs[j][i] < strs[j + 1][i]) {
                resolved[j] = i;
            }
        }
    }

    return reduce;
}
