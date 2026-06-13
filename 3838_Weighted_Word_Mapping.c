char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    char *result = (char *)malloc((wordsSize + 1) * sizeof(char));

    for(int i = 0; i<wordsSize; i++){
        int temp = 0;
        char ch='a';
        for(int j = 0; words[i][j]!='\0'; j++){
            ch = words[i][j];
            temp += weights[ch-'a'];
            temp %= 26;
            ch = (char)('z'-temp);
        }
        result[i]=ch;
    }
    result[wordsSize] = '\0';
    return result;
}
