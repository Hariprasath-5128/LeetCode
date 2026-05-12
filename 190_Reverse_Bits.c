#include <math.h>

int reverseBits(int n) {
    int bits[32];

    for(int i = 31; i>=0; i--){
        bits[31-i] = (n>>i) & 1;
    }

    int result = 0;

    for(int i = 31; i>=0; i--){
        result += bits[31-i] * pow(2,31-i);
    }

    return result;
}