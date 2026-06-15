/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    //Analyse the pattern; for p=23(10111 , the answer is 19(10011), just flipping the bit that comes before the first zero from LSB)

    *returnSize = numsSize;

    int *ans = malloc(numsSize * sizeof(int));

    for(int i = 0; i<numsSize; i++){
        if(nums[i]==2){
            ans[i]=-1;
            continue;
        }
        int pos =0;
        while(nums[i]&(1<<pos))
            pos++; //Finding the first zero's position from the LSB

        ans[i] = nums[i]^(1<<(pos-1));//flipping the bit, that is before the first zero's position
    }
    return ans;
}
