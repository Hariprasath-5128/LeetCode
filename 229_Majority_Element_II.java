class Solution {
    public List<Integer> majorityElement(int[] nums) {

        // Handle empty array edge case safely
        if (nums == null || nums.length == 0) {
            return new ArrayList<>();
        }

        //Using Boyer-Moore Majority Voting Method

        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 0;

        //This loop will show which two elements will be higher
        for(int i = 0; i < nums.length; i++){
            int a = nums[i];

            if(a == candidate1)
                count1++;
            else if(a == candidate2)
                count2++;

            else if(count1 == 0){
                count1++;
                candidate1 = a;
            }    
            else if(count2 == 0){
                count2++;
                candidate2 = a;
            }

            else{
                count1--;
                count2--;
            }

        }

        //Now check the actual threshold of the maximum elements in the array
        int threshold = nums.length / 3;
        count1 = 0;
        count2 = 0;

        for(int i = 0; i < nums.length; i++){
            if(candidate1 == nums[i]){
                count1++;
            }
            else if(candidate2 == nums[i]){
                count2++;
            }
        }

        //Check if the counts of the potential majority elements are greater than n/3 and add them to the result.

        List<Integer> result = new ArrayList<>();
        if(count1 > threshold)
            result.add(candidate1);
        if(count2 > threshold)
            result.add(candidate2);

        return result;
    }
}
