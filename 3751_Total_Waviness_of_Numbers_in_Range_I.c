int waviness(int a){
    int digit[10];
    int len = 0;
    int count = 0;

    while(a != 0){
        digit[len++] = a%10;
        a/=10;
    }
    //No need to reverse however we're going to count the total number of peak and valley

    for(int i = 1; i<len -1; i++){
        if((digit[i-1] > digit[i] && digit[i+1] > digit[i])||(digit[i-1] < digit[i] && digit[i+1] < digit[i]))
            count++;
    }
    return count;
}

int totalWaviness(int num1, int num2) {
    int ans = 0;

    for(int i = num1; i<num2+1; i++){
        ans += waviness(i);
    }
    return ans;
}
