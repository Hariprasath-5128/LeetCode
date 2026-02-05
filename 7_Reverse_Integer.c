#include <math.h>

int reverse(int x){
    int result=0;
    while(x!=0){  /*use x!=0 instead of x>0, so as it should work for the negative numbers*/
        int digit=x%10;
        x=x/10;
        if(result > 214748364 || result < -214748364) return 0;
        result=result*10+digit;
    }
    return result;
}