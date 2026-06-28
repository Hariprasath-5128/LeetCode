int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minRemoval(int* nums, int numsSize, int k) {
    int n = numsSize;
    qsort(nums, n, sizeof(int), cmp);

    //Minimum removal - maximum window size
    int left = 0;
    int maxKeep = 0;

    //After sorting:
        //nums[left] is the minimum of the window.
        //nums[right] is the maximum of the window.

    //nums[right] <= nums[left] * k, the window is balanced.

    for(int right = 0; right < n; right++){
        while((long long) nums[right] > (long long) nums[left] * k)
            left++;

        if(right - left +1 > maxKeep)
            maxKeep = right - left + 1;
    }
    return n - maxKeep;
}