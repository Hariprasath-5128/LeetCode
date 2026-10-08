class Solution {
    public int splitArray(int[] nums, int k) {
        int right = 0; //The maximum range is sum of all elements
        int left = 0; // The minimum range is maximum element of the array
        for(int i : nums){
            right += i;
            left = Math.max(i, left);
        }

        while(left < right){
            int mid = left + (right - left)/2;

            int count = 1; //Count the number of subarray
            int sum = 0;
            for(int i : nums){
                sum += i;
                if(sum > mid){
                    count++;
                    sum = i;
                }
            }

            if(k >= count){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }

        return left;
    }
}
