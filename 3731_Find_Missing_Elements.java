class Solution {
    public List<Integer> findMissingElements(int[] nums) {

        int max = Arrays.stream(nums).max().getAsInt();
        int min = Arrays.stream(nums).min().getAsInt();

        int n = nums.length;
        List<Integer> result = new ArrayList<>(nums.length);
        int[] count = new int[max + 1];

        if(max - min == n - 1)
            return result;

        for(int i = 0; i < n; i++){
            count[nums[i]]++;
        }

        for(int i = min; i < max + 1; i++){
            if(count[i] != 1)
                result.add(i);
        }

        return result;
    }
}
