#include <string.h>

int longestBalanced(char* s) {
    int n = strlen(s);
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        int freq[26] = {0};

        for (int j = i; j < n; j++) {

            // Add the new character
            freq[s[j] - 'a']++;

            int target = 0;
            int valid = 1;

            // Check if all non-zero frequencies are equal
            for (int k = 0; k < 26; k++) {
                if (freq[k] != 0) {
                    if (target == 0)
                        target = freq[k];
                    else if (freq[k] != target) {
                        valid = 0;
                        break;
                    }
                }
            }

            if (valid && (j - i + 1) > maxLen)
                maxLen = j - i + 1;
        }
    }

    return maxLen;
}
