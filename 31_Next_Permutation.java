class Solution {
    public void nextPermutation(int[] nums) {
        int ptr = -1;
        int n = nums.length;

         // Find the first element from the right that is smaller than its next element
        // This is the element that we need to increase
        for(int i = n-1; i >= 1; i--){
            if(nums[i] > nums[i - 1]){
                ptr = i-1;
                break;
            }
        }

        int i = ptr;
        if(i >= 0){
            int j = n - 1;
            while(nums[j] <= nums[i]){ //If we traverse from right it is already, in descending order;
                j--;
            }

            swap(nums, i, j); //Because upto the breaking point it is maximum number, where we can't reorder the portion; So we choose the smallest greater element than nums[i] so that it could reach the next immediate series.
        }

        reverse(nums, i + 1, n); //Reversing because the right portion is already now in the descending order, now we changed it to the new series - now we should make the right portion (Descending order) to the ascending order to start the series
    }

    private void reverse(int[] nums, int start, int n){
        int i = start, j = n - 1;
        while(i < j){
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
