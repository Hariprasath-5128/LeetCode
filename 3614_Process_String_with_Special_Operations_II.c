typedef long long ll;

char processStr(char* s, long long k) {

    int n = strlen(s);
    // len[i] = length after processing s[0..i]
    ll* len = malloc(sizeof(ll)*n);

    ll curr = 0;

    for(int i = 0; i<n; i++){
        if(s[i]>='a' && s[i]<='z')
            curr++;

        else if(s[i]=='*'){
            if(curr>0)
                curr--;
        }

        else if(s[i]=='#')
            curr*=2;

        else if(s[i] == '%'){
        //No change
        }

        len[i] = curr;
    }

    // k out of bounds
    if (k >= curr) {
        free(len);
        return '.';
    }

    //walk Backwards, because then only we can change the 'k' value dynamically and finally making it point to some character
    for(int i = n-1; i>=0; i--){

        ll prevLen = (i==0) ? 0:len[i-1];

        if(s[i] >='a' && s[i] <='z'){
            //This character was appended at position prevLen
            if(k==prevLen){
                char ans=s[i];
                free(len);
                return ans;
            }
        }

        else if(s[i]=='#'){
            //Before duplication length was prevLen
            if (prevLen > 0)
                k%=prevLen;
        }
        else if(s[i] == '%'){
            //Reverse mapping
            k=prevLen-1-k;
        }
        else if(s[i]=='*'){
            //Length before deletion = prevLen
            //Current valid indices are unchaged
            //so k stays the same
        }
    }
    free(len);
    return '.';
}