class Solution {
    public int maxDepth(String s) {
        int sp = 0;
        int max = 0;

        for(char c : s.toCharArray()){
            if(c == '('){
                sp++;
                max = Math.max(sp, max);
                continue;
            }
            else if(c == ')')
                sp--;
        }
        return max;
    }
}
