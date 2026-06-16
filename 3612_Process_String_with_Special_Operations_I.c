char* processStr(char* s) {
    int capacity = 16;
    int len = 0;

    char *result = malloc(capacity);

    for(int i =0; s[i] != '\0'; i++){
        if(s[i]>='a' && s[i]<='z'){
            if(len + 1 >= capacity){
                capacity *= 2;
                result = realloc(result, capacity);
            }
            result[len++] = s[i];
        }
        else if(s[i]=='*'){
            if(len>0)
                len--;
        }
        else if(s[i]=='#'){
            if(2*len >= capacity){
                capacity *= 2;
                result = realloc(result, capacity);
            }
            memcpy(result + len, result, len);
            len *= 2;
        }
        else if (s[i] == '%') {

            for (int l = 0, r = len - 1; l < r; l++, r--) {
                char t = result[l];
                result[l] = result[r];
                result[r] = t;
            }
        }
    }
    result[len]='\0';
    return result;
}
