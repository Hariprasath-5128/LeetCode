int rearrangeCharacters(char* s, char* target) {
    int freq_s[26];
    int freq_target[26];

    for(int i = 0; s[i]; i++){
        freq_s[s[i]-'a']++;
    }
    for(int i = 0; target[i]; i++){
        freq_target[target[i]-'a']++;
    }

    int min = 100000;
    int valid = 1;

    for(int i = 0; i<26; i++){
        if(freq_target[i] <= freq_s[i] && freq_target[i] != 0){
            min = fmin(min, freq_s[i]/freq_target[i]);
        }
        else if(freq_target[i] > freq_s[i]){
            valid = 0;
            break;
        }
    }
    if(valid==0)
        return 0;
    return min;
}