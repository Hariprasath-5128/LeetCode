class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;
        int count0 = 1;
        int countN = 0;

        int[] freq = new int[51];

        // Initialize max with the first element of the array
        freq[nums[0]]++;

        // Loop through the rest of the array
        for (int i = 1; i < nums.length; i++) {
            freq[nums[i]]++;
        }

        int max = -1;
        for(int i = 0; i < nums.length; i++){
            if(freq[nums[i]] == 1 && max <  nums[i])
                max = nums[i];
        }

        if(k == 1){
            return max;
        }  

        if(k == n){
            //when k == n, every distinct value is in one subarray.
            // Find the largest value again.
            max = nums[0];

            for(int i = 1; i < nums.length; i++)
                max = Math.max(max, nums[i]);

            return max;
        }

        // For 1 < k < n, count whether first/last value
        // occurs outside its only possible window.

        count0 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[0]){
                count0++;
            }
        }

        countN = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[n-1]){
                countN++;
            }
        }

        if(count0 == 1 && countN==1 && nums[0] != nums[n-1]){
            System.out.println(count0);
            System.out.println(countN);


            return Math.max(nums[n-1], nums[0]);
        }

        else if((count0 > 1 && countN > 1)||nums[0] == nums[n-1])
            return -1;

        else{
            int ans = count0 < countN ? nums[0]:nums[n-1];
            return ans;
        }
    }
}