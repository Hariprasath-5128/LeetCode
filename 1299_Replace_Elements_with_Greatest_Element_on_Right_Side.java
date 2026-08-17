class Solution {
    public int[] replaceElements(int[] arr) {
        int n = arr.length;
        if(n == 1)
            return new int[] {-1};

        // Flow: Traverse from right to left and keep track of the greatest element seen on the right.
        int max = Integer.MIN_VALUE;
        int[] result = new int[n];

        for(int i = n-1; i>=0; i--){
            if(i==n-1){
                // The rightmost element has no element to its right.
                result[i] = -1;
                max = arr[i];
                continue;
            }
            
            // Store the greatest element that was already seen on the right.
            result[i] = max;

            // Update max if the current element is greater.
            if(max <= arr[i]){
                max = arr[i];
            }
        }

        return result;
    }
}
