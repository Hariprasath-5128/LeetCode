int maxIceCream(int* costs, int costsSize, int coins) {
    int maxLen = 0;
    for(int i = 0; i<costsSize; i++){
        if(maxLen < costs[i])
            maxLen = costs[i];
    }

    int sorted[maxLen + 1];
    for(int i = 0; i <= maxLen; i++)
        sorted[i] = 0;

    for(int i = 0; i<costsSize; i++){
        sorted[costs[i]]++;
    }

    int count = 0;
    for(int i=1; i<=maxLen; i++){
        while(sorted[i]!=0 && coins>=i){
            count++;
            sorted[i]--;
            coins-=i;
        }
        if(coins<i)
            break;
    }
    return count;
}