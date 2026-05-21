/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {

    int low = 0;
    int high = numsSize - 1;

    int start = -1, end = -1;

    while(low <= high){

        int mid = low + (high - low)/2;

        if(nums[mid] == target){

            if(mid > 0 && nums[mid] == nums[mid-1]){
                high = mid - 1;
            }
            else{
                start = mid;
                break;
            }
        }

        else if(nums[mid] > target){
            high = mid - 1;
        }

        else{
            low = mid + 1;
        }
    }

    low = 0;
    high = numsSize - 1;

    while(low <= high){

        int mid = low + (high - low)/2;

        if(nums[mid] == target){

            if(mid != numsSize - 1 && nums[mid] == nums[mid+1]){
                low = mid + 1;
            }
            else{
                end = mid;
                break;
            }
        }

        else if(nums[mid] > target){
            high = mid - 1;
        }

        else{
            low = mid + 1;
        }
    }

    int *ans = (int*)calloc(2, sizeof(int));

    if(end == -1 || start == -1){
        ans[0] = -1;
        ans[1] = -1;
    }
    else{
        ans[0] = start;
        ans[1] = end;
    }

    *returnSize = 2;

    return ans;
}
