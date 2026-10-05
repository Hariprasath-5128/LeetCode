class Solution {
    public boolean checkPerfectNumber(int num) {
        int res = 0;
        if(num == 1)
            return false;

        for(int i = 1; i*i <= num; i++){
            if(num%i == 0){
                res += i;

                if(i!=1 && i*i != num) {//avoid adding the number to itself and having a perfect square too
                    res += num/i;
                }
            }
        }
       // System.out.println(res);
       return res == num;
    }
}
