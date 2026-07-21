class Solution {
    public int numSteps(String s) {
        int steps = 0;
        int carry = 0;

        //Traverse from right to left, except the first flow
        for(int i = s.length() -1; i >=1; i--){

            // Current bit after considering any carry from a previous +1 operation
            int bit = (s.charAt(i) - '0') + carry;

            if(bit == 1){
                steps += 2; // Add 1 and divide by 2
                carry = 1;
            }
            else{
                steps += 1;
            }
        }

        //for numbers like 8,4,2 the carry will be 0 (as there is no addition, it can safely moves to right to left)
        //for the other numbers, the carry = 1 (after any bit == 1 before the MSB), there will be stuck up at '10' in the end with no more traversing.

        return carry + steps;
    }
}
