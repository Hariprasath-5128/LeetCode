/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int size = 0;

    for(int i = 0; i < numsSize; i++) {

        int x = nums[i];

        while(x > 0) {
            size++;
            x /= 10;
        } 
    }

    int *ans = malloc(size * sizeof(int));
    *returnSize = size;

    int k = 0;

    for(int i = 0; i < numsSize; i++) {

        int x = nums[i];
        int start = k;

        while(x > 0) {
            ans[k] = x % 10;
            x /= 10;
            k++;
        } 

        int end = k - 1;

        while(start < end) {

            int temp = ans[start];
            ans[start] = ans[end];
            ans[end] = temp;

            start++;
            end--;
        }
    }

    return ans;
}
