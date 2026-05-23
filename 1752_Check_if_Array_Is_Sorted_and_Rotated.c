#include <stdbool.h>

bool check(int* nums, int numsSize) {
    int count = 0;

    for(int i = 0; i < numsSize; i++) {

        // circular next index
        if(nums[i] > nums[(i + 1) % numsSize]) {
            count++;
        }

        // more than one break -> invalid
        if(count > 1) {
            return false;
        }
    }

    return true;
}
