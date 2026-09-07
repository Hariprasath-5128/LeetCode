class Solution {
    public String largestOddNumber(String num) {
        int len = num.length();
        int i = 0;

        for(i = len - 1; i >= 0; i--){
            if((num.charAt(i) - '0') % 2 == 1){
                break;
            }
        }
        return i == -1 ? "" : num.substring(0, i + 1);
    }
}
