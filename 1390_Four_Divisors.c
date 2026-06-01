int sumFourDivisors(int* nums, int numsSize) {
    //instead of check for all range numbers from 1 to m, simply check it upto root(m) - it will seperate all the pair of multiple.
    
    /*
    For 21: (1, 21),(3, 7)
    Notice that in each pair:
    One divisor is ≤ √21
    The other is ≥ √21
    */

    int ans = 0;

    for(int i = 0; i < numsSize; i++) {
        int count = 0;
        int sum = 0;

        for(int j = 1; j * j <= nums[i]; j++) {
            if(nums[i] % j == 0) {
                int other = nums[i] / j;

                if(j == other) {
                    count++;
                    sum += j;
                } else {
                    count += 2;
                    sum += j + other;
                }

                if(count > 4)
                    break;
            }
        }

        if(count == 4)
            ans += sum;
    }

    return ans;
}
