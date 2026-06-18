int longestValidParentheses(char* s) {
    int left = 0, right = 0, ans = 0;

    //Use two-pointer approach
    for(int i = 0; s[i]; i++){
        if(s[i] == '('){
            left++;
        }
        else
            right++;

        if(left == right)
            ans = fmax(ans, 2*right);
        else if(right>left)
            right = left = 0;
    }

    right = left = 0;

    for(int i = strlen(s)-1; i>=0; i--){
        if(s[i] == '('){
            left++;
        }
        else
            right++;

        if(left == right)
            ans = fmax(ans, 2*left);
        else if(right<left)
            right = left = 0;
    }
    return ans;
}
