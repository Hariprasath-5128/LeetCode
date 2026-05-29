int minElement(int* nums, int numsSize) {
    int min = 10001;

    for(int i = 0; i < numsSize; i++) {
        int sum = 0;
        int temp = nums[i];

        while(temp > 0) {
            int t = temp % 10;
            sum += t;
            temp /= 10;
        }

        if(min > sum)
            min = sum;
    }

    return min;
}
