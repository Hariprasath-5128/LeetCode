class Solution {
    public boolean isMonotonic(int[] nums) {
        int dir = 0; // 0 - increasing, 1 - decreasing

        if (nums[0] <= nums[nums.length - 1]) {
            dir = 0;
        } else {
            dir = 1;
        }

        for (int i = 0; i < nums.length - 1; i++) {
            if (dir == 0 && nums[i] > nums[i + 1])
                return false;

            if (dir == 1 && nums[i] < nums[i + 1])
                return false;
        }

        return true;
    }
}
