/*
Solution 1:
Time Complexity: O(NlogN)

import java.util.Arrays;

class Solution {
    public int longestConsecutive(int[] nums) {

        if(nums.length == 0)
            return 0;

        Arrays.sort(nums);

        int count = 1;
        int max = 0;

        for(int i = 0; i < nums.length - 1; i++){
            if(nums[i] == nums[i+1])
                continue;
            if(nums[i] + 1 == nums[i+1]){
                count++;
            }
            else{
                if(max < count){
                    max = count;
                }
                count = 1;
            }
        }

        if(max < count)
            max = count;

        return max;
    }
}

*/

//Solution 2:
//Time Complexity : O(N)
class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer, Integer> arrPos = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            if(arrPos.getOrDefault(nums[i], 0) == 0){
                arrPos.put(nums[i], i);
            }
        }

        int longest = 0;

        for(int num: arrPos.keySet()){
            if(!arrPos.containsKey(num - 1)){
                int currentNum = num;
                int currentStreak = 1;

                //Count consecutive from this
                while(arrPos.containsKey(currentNum + 1)){
                    currentNum++;
                    currentStreak++;
                }

                longest = Math.max(longest, currentStreak);
            }
        }

        return longest;
    }
}


