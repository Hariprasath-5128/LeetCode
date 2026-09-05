class Solution { 
    long answer = 0; 

    public void check(int[] nums, int left, int right, int mid){ 

        int j = mid + 1; 
        for(int i = left; i <= mid; i++){ 
            while(j <= right && (long) nums[i] > 2L * nums[j]){ 
                j++; 
            } 

            answer += j - (mid + 1); 
        } 
    } 

    public void merge(int[] nums, int left, int right, int mid){ 
        int[] temp = new int[right - left + 1]; 
        int i = left; 
        int j = mid + 1; 
        int k = 0; 

        while(i <= mid && j <= right){ 
            if(nums[i] <= nums[j]) 
                temp[k++] = nums[i++]; 
            else 
                temp[k++] = nums[j++]; 
        } 

        while(i <= mid){ 
            temp[k++] = nums[i++]; 
        } 

        while(j <= right){ 
            temp[k++] = nums[j++]; 
        } 

        for(int x = 0; x < temp.length; x++){ 
            nums[left + x] = temp[x]; 
        } 
    } 

    public void divide(int[] nums, int left, int right){ 
        if(left >= right) 
            return; 

        int mid = left + (right - left)/2; 

        divide(nums, left, mid); 
        divide(nums, mid + 1, right); 
        check(nums, left, right, mid); 

        //Here merging because it eliminates the duplicate checking (or repeated checking)
        merge(nums, left, right, mid); 
    } 

    public int reversePairs(int[] nums) { 
        int left = 0; 
        int right = nums.length - 1; 

        divide(nums, left, right); 
        return (int) answer; 
    } 
}
