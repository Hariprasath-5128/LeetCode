class Solution {
    public String removeOuterParentheses(String s) {
        int sp = -1;
        StringBuilder str = new StringBuilder();

        for(int i = 0; i < s.length(); i++){
            char t = s.charAt(i);

            if(t == '('){
                sp++;
                if(sp >= 1) str.append(t);
                continue;
            }
            sp--;
            if(sp >= 0) str.append(t);

        }
        return str.toString();
    }
}