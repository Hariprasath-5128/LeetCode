int sumOfGoodIntegers(int n, int k) {
    int sum = 0;

    int start = n - k;
    if(start < 0)
        start = 0;

    for(int x = start; x <= n + k; x++) {
        if((x & n) == 0)
            sum += x;
    }

    return sum;
}