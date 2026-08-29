class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int ans = 0;
        int min = 100000;
        Arrays.sort(nums);
        int n = nums.length;

        for(int i = 0; i < n; i++){
            int l = 0;
            int r = n- 1;
            int fix = nums[i];

            while(l < r){ //no l = r; as it should be minimum windows size of 2

                if(l == i) {
                    l++;
                    continue;
                }
                if(r == i) {
                    r--;
                    continue;
                }
                int sum = fix + nums[l] + nums[r];

                if(sum == target)
                    return target;

                else if(sum > target){
                    r--;
                    if(min > Math.abs(target - sum)){
                        min = Math.abs(target - sum);
                        ans = sum;
                    }
                }
                else if(sum < target){
                    l++;
                    if(min > Math.abs(target - sum)){
                        min = Math.abs(target - sum);
                        ans = sum;
                    }
                }
            }
        }

        return ans;
    }
}