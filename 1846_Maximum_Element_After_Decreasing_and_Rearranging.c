int min(int a, int b){
    return a > b ? b:a;
}

//Dry Run method , O(N)
int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {

    int n = arrSize;
    int *cnt = (int*)malloc(sizeof(int)*(n + 1));
    memset(cnt, 0,  sizeof(int) * (n + 1));

    //Freq array
    for(int i = 0; i<arrSize; i++){
        cnt[min(arr[i], n)]++;
    }

    //We're gonna only decrease the element of 'arr'
    int val = 0;
    for(int i = 1; i<=n; i++){
        val = min(i, val+cnt[i]);
        //val + cnt[i] = how far the sequence could extend if there were no value limit
        //i = the maximum value these elements can have, since they started as i and can only be decreased
        //By taking the minimum element along these, enforces the decrease only rule
    }
    return val;
}