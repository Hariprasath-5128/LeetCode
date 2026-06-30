bool isTrionic(int* nums, int numsSize) {

    if(numsSize < 4){
        return false;
    }

    int noOfChange = 0;
    int dir = 1; // Initially, it is strictly increasing
    // +1 = increasing, -1 = decreasing

    int prev = nums[0];

    for(int i = 1; i < numsSize; i++){

        // Strictly increasing/decreasing only
        if(prev == nums[i])
            return false;

        //reject arrays whose first comparison is not increasing
        if(i == 1 && nums[i] <= nums[i - 1])
            return false;

        if(noOfChange < 3){
            if(prev < nums[i] && dir == 1){
                prev = nums[i];
                continue;
            }

            else if(prev < nums[i] && dir == -1){
                prev = nums[i];
                dir = 1;
                noOfChange++;
                continue;
            }

            else if(prev > nums[i] && dir == -1){
                prev = nums[i];
                continue;
            }

            else if(prev > nums[i] && dir == 1){
                prev = nums[i];
                dir = -1;
                noOfChange++;
                continue;
            }
        }
        else{
            return false; // More than 2 direction changes
        }
    }

    return noOfChange == 2;
}
