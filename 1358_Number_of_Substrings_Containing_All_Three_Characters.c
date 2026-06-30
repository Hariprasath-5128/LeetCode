int numberOfSubstrings(char* s) {
    int freq[3];
    int len = strlen(s);
    int ans = 0;
    int left = 0;

    //Expand the right pointer until it finds a valid substring (that has 'a', 'b', 'c')
    for(int right = 0; right < len; right++){
        freq[s[right] - 'a']++;

        while(freq[0] && freq[1] && freq[2]){
            ans += (len - right);
            freq[s[left] - 'a']--;
            left++;
        }
    }
    return ans;
}
