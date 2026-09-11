class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            int j = map.getOrDefault(nums[i], -1);
            map.put(nums[i], i);
            if(j != -1 && Math.abs(i-j) <= k)
                return true;
        }

        return false;
    }
}