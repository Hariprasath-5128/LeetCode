#include <string.h>

int bestClosingTime(char* customers) {

    int len = strlen(customers);

    int ycount[len + 1];
    int ncount[len + 1];

    int y = 0, n = 0;

    // initialize
    for(int i = 0; i <= len; i++) {
        ycount[i] = 0;
        ncount[i] = 0;
    }

    // suffix count of Y
    for(int i = len - 1; i >= 0; i--) {
        if(customers[i] == 'Y') {
            y++;
        }
        ycount[i] = y;
    }

    // prefix count of N
    for(int i = 0; i < len; i++) {
        ncount[i + 1] = ncount[i];

        if(customers[i] == 'N') {
            ncount[i + 1]++;
        }
    }

    int min = 1000000;
    int minhr = 0;

    for(int i = 0; i <= len; i++) {

        int penalty = ycount[i] + ncount[i];

        if(min > penalty) {
            min = penalty;
            minhr = i;
        }
    }

    return minhr;
}
