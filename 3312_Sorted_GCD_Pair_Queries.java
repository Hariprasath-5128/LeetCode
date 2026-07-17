class Solution {
    public int[] gcdValues(int[] nums, long[] queries) {

        // Step 1 - Find the maximum value in nums
        int max = 0;
        for(int num: nums){
            max = Math.max(max, num);
        }

        // Step 2 - Count frequency of each number
        int[] cnt = new int[max + 1];

        for(int num : nums){
            cnt[num]++;
        }

        // Step 3 - Find how many pairs have GCD exactly i
        long[] exact = new long[max + 1];

        // Process from maximum to 1
        for(int i = max; i >= 1; i--){
            // Count how many numbers are divisible by i
            int divisible = 0;

            for(int multiple = i; multiple <= max; multiple += i){
                divisible += cnt[multiple];
            }

            // Number of pairs formed by numbers divisible by i
            exact[i] = (long) divisible * (divisible - 1) / 2;

            // Remove the pairs having GCD as a higher multiple of i
            // It is similar to checking: 2*i, 3*i, 4*i, ...
            for(int multiple = 2 * i; multiple <= max; multiple += i){
                exact[i] -= exact[multiple];
            }
        }

        // Step 4 - Build prefix sum
        // prefix[i] = number of pairs having GCD <= i
        long[] prefix = new long[max + 1];

        for(int i = 1; i <= max; i++){
            prefix[i] = prefix[i - 1] + exact[i];
        }

        // Step 5 - Answer each query using binary search
        int[] answer = new int[queries.length];

        for(int q = 0; q < queries.length; q++){

            long query = queries[q];

            // Binary search for the smallest GCD where prefix[GCD] > query
            int left = 1;
            int right = max;

            while(left < right){

                int mid = left + (right - left) / 2;

                if(prefix[mid] > query){
                    // mid could be the answer, but try to find a smaller GCD
                    right = mid;
                }
                else{
                    // mid is too small
                    // answer must be on the right
                    left = mid + 1;
                }
            }

            answer[q] = left;
        }

        return answer;
    }
}
