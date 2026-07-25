class Solution {
    public int minOperations(String s) {
        //There are the two alternatives, check the count that starting with 0 and starting with 1

        int start0 = 0; 
        int start1 = 0;

        for(int i = 0 ; i < s.length(); i++){
            if(i % 2 == 0){
                if(s.charAt(i) == '0')
                    start1++;
                else
                    start0++;
            }

            else{
                if(s.charAt(i) == '0')
                    start0++;
                else
                    start1++;
            }
        }

        return Math.min(start0, start1);
    }
}
