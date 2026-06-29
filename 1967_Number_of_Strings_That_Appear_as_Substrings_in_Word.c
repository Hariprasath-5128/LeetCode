bool naive(char* word, char* pattern){
    int count = 1;

    int patternLen = strlen(pattern);
    int wordLen = strlen(word);

    for(int i = 0; i<=wordLen - patternLen; i++){

        count = 1;
        if(word[i] == pattern[0]){

            if(patternLen == 1)
                return true;

            for(int j = 1; j<patternLen; j++){
                if(word[i+j] == pattern[j]){
                    count++;
                    if(count == patternLen)
                        return true;
                }
                else 
                    break;

            }
        }
    }
    return false;
}

int numOfStrings(char** patterns, int patternsSize, char* word) {

    int res = 0;
    for(int i = 0; i<patternsSize; i++){
        if(naive(word, patterns[i]))
            res++;
    }
    return res;
}