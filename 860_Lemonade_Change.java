class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fives = 0;
        int tens = 0;

        for(int bill: bills){
            if(bill == 5)
                fives++;

            else if(bill == 10){
                fives--;
                tens++;
                if(fives < 0)
                    return false;
            }
            else if(bill == 20){

                //This is the first if condition as the $10 should complete first
                if(fives >= 1 && tens >= 1){
                    fives--;
                    tens--;
                }

                else if(fives >= 3)
                    fives -= 3;


                else{
                    return false;
                }
            }
        }

        return true;
    }
}
