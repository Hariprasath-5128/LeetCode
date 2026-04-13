#include <string.h>
#include <limits.h>

int myAtoi(char* s) {
    long result = 0;
    int isneg = 0;
    int ischar = 0;
    int isfirst = 0;

    for(int i = 0; i<strlen(s); i++){
        int digit = s[i]-'0';
        if(isfirst == 0 && s[i] == ' '){
            continue;
        }

        if(isfirst == 0) {
            isfirst = 1;

            if(s[i] == '-') {
                isneg = 1;
                continue;
            }
            else if(s[i] == '+') {
                continue;
            }
        }

        if(s[i] < '0' || s[i] > '9') {
            break;
        }


        /*If I multiply result by 10 and add digit… will it exceed INT_MAX*/
        if (!isneg && (result > (INT_MAX - digit) / 10))
            return INT_MAX;

        if (isneg && (-result < (INT_MIN + digit) / 10))
            return INT_MIN;

        result = result * 10 + digit;
    }
        return isneg ? -result : result;

}