class Solution {

    List<Integer> answer = new ArrayList<>(); 

    public void check(int[][] nums, int left, int right, int mid){ 

        int j = mid + 1; 
        for(int i = left; i <= mid; i++){ 
            while(j <= right && nums[i][0] > nums[j][0]){ 
                j++; 
            } 

            int originalIndex = nums[i][1];
            int val = answer.get(originalIndex) + (j - (mid + 1)); 
            answer.set(originalIndex, val);
        } 
    } 


    public void merge(int[][] nums, int left, int right, int mid){ 
        int[][] temp = new int[right - left + 1][2]; 
        int i = left; 
        int j = mid + 1; 
        int k = 0; 

        while(i <= mid && j <= right){ 
            if(nums[i][0] <= nums[j][0]) 
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

    public void divide(int[][] nums, int left, int right){ 
        if(left >= right) 
            return; 

        int mid = left + (right - left)/2; 

        divide(nums, left, mid); 
        divide(nums, mid + 1, right); 
        check(nums, left, right, mid); 

        //Here merging because it eliminates the duplicate checking (or repeated checking)
        merge(nums, left, right, mid); 
    } 

    public List<Integer> countSmaller(int[] nums) {
        int left = 0; 
        int right = nums.length - 1; 
        int n = nums.length;

        for (int i = 0; i < nums.length; i++) {
            answer.add(0);
        }

        int[][] arr = new int[n][2];
        for(int i = 0; i < n; i++){
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }

        divide(arr, left, right); 
        return answer; 
    }
}