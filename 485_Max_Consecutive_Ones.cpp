#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                count = 0;
            }
            ans = max(ans, count);
        }

        return ans;
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};
