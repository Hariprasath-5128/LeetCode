int numberOfSpecialChars(char* word) {
    int freqlower[26] = {0};
    int frequpper[26] = {0};

    for(int i = 0; i < strlen(word); i++){
        if(word[i] >= 65 && word[i] <= 90)
            frequpper[word[i] - 'A']++;

        if(word[i] >= 97 && word[i] <= 122)
            freqlower[word[i] - 'a']++;
    }

    int count = 0;

    for(int j = 0; j < 26; j++){
        if(frequpper[j] > 0 && freqlower[j] > 0) 
            count++;
    }

    return count;
}
