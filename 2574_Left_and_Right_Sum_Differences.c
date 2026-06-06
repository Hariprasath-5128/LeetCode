/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    
    int leftSum[numsSize], rightSum[numsSize];
    int* answer = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    leftSum[0] = 0;
    rightSum[numsSize-1]=0;
    int sum = 0;
    
    for(int i=1; i<numsSize; i++){
        sum+=nums[i-1];
        leftSum[i]=sum;
    }

    sum=0;
    for(int i=numsSize-2; i>=0; i--){
        sum+=nums[i+1];
        rightSum[i]=sum;
    }

    for(int i=0; i<numsSize; i++){
        answer[i]=abs(leftSum[i]-rightSum[i]);
    }
    return answer;
}
