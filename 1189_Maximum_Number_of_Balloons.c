int maxNumberOfBalloons(char* text) {
    int b = 0, a =0, l=0, o=0, n=0;
    for(int i=0; text[i]; i++){
        char t = text[i];
        if(t=='b')
            b++;
        else if(t=='a')
            a++;
        else if(t=='l')
            l++;
        else if(t=='o')
            o++;
        else if(t=='n')
            n++;
    }

    l/=2;
    o/=2;

    int min = fmin(b, a);
    min = fmin(min, l);
    min = fmin(min, o);
    min = fmin(min, n);

    return min;
}