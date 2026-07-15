class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sumOfCurrentWindow = 0;
        int res = INT_MAX;

        for(right = 0; right < nums.size(); right++){
            sumOfCurrentWindow += nums[right];

            while(sumOfCurrentWindow >= target){
                sumOfCurrentWindow -= nums[left];
                res = min(res, right - left + 1);
                left++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
