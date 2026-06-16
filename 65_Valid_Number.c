bool isNumber(char* s) {
    bool seenDigit = false;
    bool seenDot = false;
    bool seenExp = false;

    for(int i = 0; s[i]; i++){
        char c = s[i];

        if (isdigit(c)) {
            seenDigit = true;
        }
        else if(s[i]=='+'||s[i]=='-'){//fixed checkpoints like before 'e' or at first position; so no need to seenSymbol
            if(i>0 && s[i-1]!='e' && s[i-1]!='E'){
                return false;
            } 
        }
        else if(s[i]=='.'){
            if(seenDot || seenExp)
                return false;
            seenDot = true;
        }
        else if(s[i]=='e'||s[i]=='E'){
            if(!seenDigit || seenExp)
                return false;
            seenDigit = false;
            seenExp = true;
        }
        else
            return false;
    }
    return seenDigit;
}
