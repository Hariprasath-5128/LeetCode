int longestBalancedSubarray(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {

        int evenDistinct = 0;
        int oddDistinct = 0;

        int *freq = (int *)calloc(100001, sizeof(int));

        for (int j = i; j < numsSize; j++) {

            if (freq[nums[j]] == 0) {
                if (nums[j] % 2 == 0)
                    evenDistinct++;
                else
                    oddDistinct++;
            }

            freq[nums[j]]++;

            if (evenDistinct == oddDistinct)
                ans = (ans > (j - i + 1)) ? ans : (j - i + 1);
        }

        free(freq);
    }

    return ans;
}
