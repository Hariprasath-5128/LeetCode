int climbStairs(int n) {

    /*Hint: this is basically following the Fibnacci Series with Ways[1] = 1 and Ways[2] = 2 */
    /*Ways[n] = Ways[n-1] (dfs like - first go to the left end with only step count = 1 (all are one)) + Ways[n-2] -->Recursive Solutions */

    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    int first,second,res;

    first = 1;
    second = 2;
    res = 0;
    
    while((n-2)>0){
        res = first+second;
        first = second;
        second = res;
        n--;
    }
    return res;
}