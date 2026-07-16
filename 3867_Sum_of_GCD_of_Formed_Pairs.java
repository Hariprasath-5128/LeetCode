import java.math.BigInteger;
import java.util.Arrays;

class Solution {
    public long gcdSum(int[] nums) {
        int[] maxPrefix = new int[nums.length];
        maxPrefix[0] = nums[0];
        int maximum = nums[0];

        for(int i = 1; i < nums.length; i++){
            if(maximum < nums[i]){
                maximum = nums[i];
            }
            maxPrefix[i] = maximum;
        }

        int[] prefixGcd = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            prefixGcd[i] = BigInteger.valueOf(maxPrefix[i]).gcd(BigInteger.valueOf(nums[i])).intValue();
        }

        Arrays.sort(prefixGcd);

        long result = 0;
        for(int i = 0; i < nums.length / 2; i++){
            result += BigInteger.valueOf(prefixGcd[i]).gcd(BigInteger.valueOf(prefixGcd[nums.length - 1 - i])).longValue();
        }

        return result;
    }
}
