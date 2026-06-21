#define MOD 1000000007

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    
    int i = 0;
    while(i < queriesSize){
        int l = queries[i][0];
        int r = queries[i][1];
        int k = queries[i][2];
        int v = queries[i][3];

        int idx = l;
        while(idx <= r){
            long long temp = ((long long)nums[idx] * v) % MOD;
            nums[idx] = temp;
            idx += k;
        }
        i++;
    }
    int result = nums[0];
    int idx = 1;
    while(idx < numsSize){
        result^=nums[idx];
        idx++;
    }
    return result;
}