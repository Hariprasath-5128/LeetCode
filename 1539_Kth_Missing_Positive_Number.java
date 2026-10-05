class Solution {
    public int findKthPositive(int[] arr, int k) {
        int left = 0;
        int right = arr.length;

        //left finally points to the first index whose missing count is NOT < k, i.e. the first index where missing count >= k.
        while(left < right){
            int mid = left + (right - left)/2;
            if(arr[mid] - mid - 1 < k)
                left = mid + 1;
            else
                right = mid; 
        }

        //answer = number of existing elements before answer + number of missing elements needed
        //= left + k

        return left + k;
    }
}
