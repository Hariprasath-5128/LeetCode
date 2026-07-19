class Solution {
    public int thirdMax(int[] nums) {

        long largest = Long.MIN_VALUE;
        long secondLargest = Long.MIN_VALUE;
        long thirdLargest = Long.MIN_VALUE;

        for (int num : nums) {

            // Skip duplicates
            if (num == largest || num == secondLargest || num == thirdLargest)
                continue;

            if (num > largest) {
                thirdLargest = secondLargest;
                secondLargest = largest;
                largest = num;
            } 
            else if (num > secondLargest) {
                thirdLargest = secondLargest;
                secondLargest = num;
            }
            else if(num > thirdLargest){
                thirdLargest = num;
            }
        }

        return thirdLargest == Long.MIN_VALUE ? (int)largest : (int)thirdLargest;
    }
}
