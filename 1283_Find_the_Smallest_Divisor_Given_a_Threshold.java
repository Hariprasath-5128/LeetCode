class Solution {
    public boolean check(int[] nums, int threshold, int mid){
        int sum = 0;
        for(int num: nums){
            //ceil(num / mid) = (num + mid - 1) / mid
            sum += (num + mid - 1) / mid;
        }

        return (sum <= threshold);
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int max = 0;
        for(int i: nums)
            max = Math.max(i, max);

        int left = 1;
        int right = max;
        int ans = 0;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(check(nums, threshold, mid)){
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return ans;
    }
}