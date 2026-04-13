int getSum(int a, int b) {
    int res = 0;
    int carr = 0;
    int sum =0;
    int pos = 0;

    while((pos<32)){
        int bit1 = a&1;
        int bit2 = b&1;
        sum = bit1^bit2^carr;
        carr = (bit1 & bit2) | ((bit1 ^ bit2) & carr);
        res |= ((unsigned int)sum<<pos);
        a = a>>1;
        b = b>>1;
        pos++;
    }
    return res;
}