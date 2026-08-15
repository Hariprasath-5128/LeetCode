/**
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int prevsign = (nums[0]) > 0 ? 1:-1;
        int ptr = 0;

        for(int i = 1; i < nums.length; i++){
            int sign = (nums[i]) > 0 ? 1:-1;

            if(prevsign == 1){
                if(sign == -1){
                    ptr++;
                    prevsign = -1;
                }
                else{
                    int t = ptr+1;
                    while(t < nums.length && nums[t] > 0){
                        t++;
                    }

                    if(t < nums.length){
                        int temp = nums[t];
                        nums[t] = nums[ptr+1];
                        nums[++ptr] = temp;
                    }
                    prevsign = -1;
                }
            }

            else if(prevsign == -1){
                if(sign == 1){
                    ptr++;
                    prevsign = 1;
                }
                else{
                    int t = ptr+1;
                    while(t < nums.length && nums[t] < 0){
                        t++;
                    }
                    if(t < nums.length){
                        int temp = nums[t];
                        nums[t] = nums[ptr+1];
                        nums[++ptr] = temp;
                    }
                    prevsign = 1;
                }
            }

        }

        int s = nums[0] > 0 ? 1:-1;
        if( s == -1 ){
            for(int i = 0; i < nums.length-1; i++){
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
            }
        }

        return nums;
    }
}

NO SWAPPING CHECK WITH THE TEST CASE: [28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31]

**/

class Solution {
    public int[] rearrangeArray(int[] nums) {
        int pos = 0;
        int neg = 1;
        int n = nums.length;
        int[] ans = new int[n];

        for(int i = 0; i<n; i++){
            if(nums[i]>0){
                ans[pos] = nums[i];
                pos+=2;
            }
            else{
                ans[neg] = nums[i];
                neg+=2;
            }
        }

        return ans;
    }
}