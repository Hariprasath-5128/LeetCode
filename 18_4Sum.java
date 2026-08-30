class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);

        for(int i = 0; i < n-3; i++){
            int first = nums[i];
            if(i > 0 && nums[i] == nums[i-1]) //To avoid duplications
                continue;

            for(int j = i+1; j < n-2; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) 
                    continue;

                int left = j + 1;
                int right = n - 1;
                int second = nums[j];

                while(left < right){

                    if(left == i || left == j) left++;
                    if(right == i || right == j) right--;

                    long sum = (long) first + second + nums[left] + nums[right];

                    if(sum == target){
                        List<Integer> temp = new ArrayList<>();
                        temp.add(first);
                        temp.add(second);
                        temp.add(nums[left]);
                        temp.add(nums[right]);

                        result.add(temp);

                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left - 1])
                            left++;

                        while(left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if(sum < target){
                        left++;
                    }
                    else if(sum > target){
                        right--;
                    }
                }
            }
        }

        return result;
    }
}