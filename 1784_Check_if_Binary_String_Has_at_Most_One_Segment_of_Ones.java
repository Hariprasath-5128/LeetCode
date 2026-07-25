class Solution {
    public boolean checkOnesSegment(String s) {

        int one = 0;

        for(int i = 0; i < s.length(); i++){
             if (s.charAt(i) == '1' && (i == 0 || s.charAt(i - 1) == '0')){
                one++;
            }
        }

        return one == 1 ? true : false;
    }
}
