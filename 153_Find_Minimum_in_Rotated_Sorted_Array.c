#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int high = numsSize - 1;
    int low = 0;

    // If array is already sorted
    if(nums[low] <= nums[high]) {
        return nums[0];
    }

    while(high > low) {

        int mid = (low + high) / 2;

        // Minimum lies in right half
        if(nums[mid] > nums[high]) {
            low = mid + 1;
        }

        // Minimum lies in left half including mid
        else {
            high = mid;
        }
    }

    // low points to the minimum element
    return nums[low];
}
