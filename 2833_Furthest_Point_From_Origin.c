int furthestDistanceFromOrigin(char* moves) {
    int ansL = 0;
    int ansR = 0;
    int ans_ = 0;

    for(int i = 0; moves[i]; i++){
        if(moves[i]=='R')
            ansR++;
        else if(moves[i]=='L')
            ansL++;
        else
            ans_++;
    }
    return abs(ansL-ansR) + ans_;
}
