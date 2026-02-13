int mySqrt(int x) {
    int result = 0;
    if(x < 0) return -1; 
    if(x == 0 || x == 1) return x;

    for(int i = 1; i<=x/2; i++){

        if(i > x/i){   /*i>x/i because i*i causes the overflow*/
            result = i-1;
            break;
        }
        else if(i*i == x) result = i;

        else result = i;
    }
    return result;
}