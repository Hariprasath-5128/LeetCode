class Solution {
    public int missingInteger(int[] nums) {
        int n = nums.length;
        Set<Integer> numSet = new HashSet<>(n);
        for (int num : nums) {
            numSet.add(num);
        }

        int ptr = 0;
        int sum = nums[0];

        for(int i = 1; i <= nums.length; i++){

            if(nums[i] ==  nums[i-1] + 1){
                sum += nums[i];
            } else {
                break;
            }
        }

        while(numSet.contains(sum)){
            sum+=1;
        }

        return sum;
    }
}