int n, m;
int dp[500][500]; //The maximum dot product that can be obtained using the suffixes : from nums1[i ... n-1], nums2[j ... m-1] ->[include i, j]

int max(int a, int b) {
    return a > b ? a : b;
}

//possible moves: i) Take i, j 
//               ii) Skip i -> i+1, j
//              iii) Skip j -> i, j+1
//By recursively, it tries all the optimal subsequence

int solve(int *nums1, int* nums2, int i, int j){
    if(i==n || j==m)
        return INT_MIN;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int product = nums1[i] * nums2[j];
    int take = product + max(0, solve(nums1, nums2, i+1, j+1));

    int skipNums1 = solve(nums1, nums2, i+1, j);
    int skipNums2 = solve(nums1, nums2, i, j+1);

    return dp[i][j] = max(take, max(skipNums1, skipNums2)); //it returns dp[i][j]
}

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    n = nums1Size;
    m = nums2Size;

    memset(dp, -1, sizeof(dp));

    return solve(nums1, nums2, 0, 0);
}