int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int minPairSum(int* nums, int numsSize){
    //To minimize the maximum pair sum, pair the smallest and largest elements together so that the pair sums stay balanced. Ex: 1 4 6 10; take pairs as (1,10) and (4,6) with sums 11 and 10. Don't take (10,6) and (1,4), which gives sums 16 and 5, because the maximum pair sum becomes larger.

    qsort(nums, numsSize, sizeof(int), compare);
    //after sorting, take the first and last elements as pair;so every pair sum is approximately equal, from that we can find maximum pair sum
    int i = 0;
    int j = numsSize - 1;
    int ans = 0;

    while(i < j){
        ans = fmax(ans, nums[i] + nums[j]);
        i++;
        j--;
    }
    return ans;
}
