class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int sumL = 0, sumR = 0, qL = 0, qR = 0;

        for(int i = 0; i<n; i++){
            char t = num.charAt(i);
            if(i < n/2){
                if(t == '?') qL++;
                else sumL+= t - '0';
            }
            else{
                if(t == '?') qR++;
                else sumR+= t - '0';
            }
        }

        //Case 1: string only contains digits
        if(qL + qR == 0)
            return sumL != sumR;

        //Case 2: odd no. of '?'
        if ((qL + qR) % 2 == 1)
            return true;

        //Case 3: even no. of '?'
        //3a:
        if(qL == qR)
            return sumL != sumR;

        //3b: 
        return 2 * (sumL - sumR) != 9 * (qR - qL);
    }
}