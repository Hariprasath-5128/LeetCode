int lengthOfLastWord(char* s) {
    int count = 0;

    for(int i = 0; s[i] != '\0'; i++) {

        if(s[i] != ' ') {
            count++;
        }
        else if(s[i+1] != ' ' && s[i+1] != '\0') {
            // new word starts after this space
            count = 0;
        }
    }

    return count;
}
