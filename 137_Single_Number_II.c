/*

nums = [2,2,3,2]

Binary:
2 = 0010
2 = 0010
3 = 0011
2 = 0010

Bit0 count = 1
1 % 3 = 1

Bit1 count = 4
4 % 3 = 1

Answer = 0011 = 3

*/

int singleNumber(int* nums, int numsSize) {
    int ans = 0;

    for(int bit = 0; bit < 32; bit++){

        int count = 0;

        for(int i = 0; i < numsSize; i++){

            if((nums[i] >> bit) & 1)
                count++;
        }

        if(count % 3)
            ans |= (1U << bit); // 001 if you shift left 31 times, it wont be in the range of int, but if it is in the unsigned int, it will be in the range.

    }
    return ans;
}
