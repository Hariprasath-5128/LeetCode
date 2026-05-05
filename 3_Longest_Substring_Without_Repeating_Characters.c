int lengthOfLongestSubstring(char* s) {
    int last[256];
    for(int i = 0; i < 256; i++){
        last[i] = -1;
    }

    int left = 0;
    int max_len = 0;

    for(int right = 0; s[right] != '\0'; right++){
        if(last[s[right]] >= left){
            left = last[s[right]] + 1;
        }

        last[s[right]] = right;
        int best_length = right - left + 1;

        if(max_len < best_length){
            max_len = best_length;
        }
    }

    return max_len;
}