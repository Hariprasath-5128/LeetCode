bool canBeEqual(char* s1, char* s2) {

    //For all the length

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if(len1 != len2)
        return false;

    bool visited1[4] = {false};
    bool visited2[4] = {false};

    for(int i = 0; i < len1; i++){

        if(s1[i] == s2[i]){
            visited1[i] = true;
            visited2[i] = true;
        }
        else if(s1[i] == s2[(i+2) % len1]){
            visited1[i] = true;
            visited2[(i+2) % len1] = true;
        }

        if((s1[i] != s2[i]) && (s1[i] != s2[(i+2) % len1])){
            return false;
        }
    }

    bool ans = true;
    for(int i = 0; i < len1; i++){
        ans = ans && visited1[i] && visited2[i];
    }

    return ans;
}
