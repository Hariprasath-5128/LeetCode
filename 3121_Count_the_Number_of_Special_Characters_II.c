#include <string.h>

int numberOfSpecialChars(char* word) {
    int freqlower[26] = {0};
    int frequpper[26] = {0};

    int n = strlen(word);

    for(int i = 0; i < n; i++) {

        if((word[i] >= 65 && word[i] <= 90 && frequpper[word[i]-'A'] == -1) ||
           (word[i] >= 97 && word[i] <= 122 && frequpper[word[i]-'a'] == -1))
            continue;

        if(word[i] >= 65 && word[i] <= 90) {

            if(freqlower[word[i]-'A'] > 0) {
                frequpper[word[i]-'A']++;
            }

            else {
                freqlower[word[i]-'A'] = -1;
                frequpper[word[i]-'A'] = -1;
            }
        }

        if(word[i] >= 97 && word[i] <= 122) {

            if(frequpper[word[i]-'a'] > 0) {
                freqlower[word[i]-'a'] = -1;
                frequpper[word[i]-'a'] = -1;
                continue;
            }

            freqlower[word[i]-'a']++;
        }
    }

    int count = 0;

    for(int j = 0; j < 26; j++) {

        if(frequpper[j] > 0 && freqlower[j] > 0)
            count++;
    }

    return count;
}
