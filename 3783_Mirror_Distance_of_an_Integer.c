int mirrorDistance(int n) {
    int x = n;
    int reverse = 0;

    while(x != 0){
        int digit = x % 10;
        reverse = reverse * 10 + digit;
        x = x / 10;
    }

    if(reverse - n > 0){
        return reverse - n;
    }
    else{
        return n - reverse;
    }
}
