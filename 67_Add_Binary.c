char* addBinary(char* a, char* b) {

    int lenA = strlen(a);
    int lenB = strlen(b);
    int newLen = fmax(lenA, lenB) + 1;

    char *ans = malloc(newLen + 1);
    ans[newLen] = '\0';

    int carry = 0;

    while (newLen > 0) {

        char bitA = (lenA > 0) ? a[lenA - 1] : '0';
        char bitB = (lenB > 0) ? b[lenB - 1] : '0';

        if (bitA == '1' && bitB == '1') {
            if (carry == 0) {
                carry = 1;
                ans[newLen - 1] = '0';
            }
            else {
                ans[newLen - 1] = '1';
            }
        }

        else if ((bitA == '0' && bitB == '1') ||
                 (bitA == '1' && bitB == '0')) {
            if (carry == 0) {
                ans[newLen - 1] = '1';
            }
            else {
                ans[newLen - 1] = '0';
            }
        }

        else {
            if (carry == 0) {
                ans[newLen - 1] = '0';
            }
            else {
                carry = 0;
                ans[newLen - 1] = '1';
            }
        }

        if (lenA > 0) lenA--;
        if (lenB > 0) lenB--;
        newLen--;
    }

    if (ans[0] == '0')//If carry is '0'; it will shift right to one position 
        return ans + 1;

    return ans;
}