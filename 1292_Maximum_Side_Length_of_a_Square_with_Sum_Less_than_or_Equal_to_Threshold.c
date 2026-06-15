bool canMake(int m, int n, int threshold, int prefix[m+1][n+1], int k){

    for(int r = 0; r+k<=m; r++){
        for(int c = 0; c+k<=n; c++){
            int sum = prefix[r+k][c+k]-prefix[r+k][c]-prefix[r][c+k]+prefix[r][c];
            if(sum<=threshold)
                return true;
        }
    }
    return false;
}

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize;
    int n = *matColSize;

    //prefix[i][j] - Sum of the rectangle from (0,0) to (i-1,j-1).
    
    int prefix[m+1][n+1]; //First row and the first column in the prefix is always zero; example: 1 2 3; prefix : 0 1 2 6 
    memset(prefix, 0, sizeof(prefix));

    //Build 2D prefix sum matrix
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            prefix[i][j] = mat[i-1][j-1]+prefix[i-1][j]+ prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    //Binary search for the size of square 
    int low = 0;
    int high = (m>n) ? n:m;
    int ans =0;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(canMake(m, n, threshold, prefix, mid)){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return ans;
}
