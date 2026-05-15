#include <stdbool.h>

int rotatedDigits(int n) {

    int count = 0;

    for(int i = 1; i <= n; i++) {

        int x = i;

        bool valid = true;
        bool changed = false;

        while(x != 0) {

            int temp = x % 10;

            if(temp == 3 || temp == 4 || temp == 7) {
                valid = false;
                break;
            }

            else if(temp == 2 || temp == 5 || temp == 6 || temp == 9) {
                changed = true;
            }

            x /= 10;
        }

        if(valid && changed) {
            count++;
        }
    }

    return count;
}
