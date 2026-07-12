class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {

        int[] components = new int[nums.length];
        components[0] = 0;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                components[i] = components[i - 1];
            } else {
                components[i] = components[i - 1] + 1;
            }
        }

        boolean[] answer = new boolean[queries.length];

        for (int i = 0; i < queries.length; i++) {
            answer[i] = components[queries[i][0]] == components[queries[i][1]];
        }

        return answer;
    }
}
