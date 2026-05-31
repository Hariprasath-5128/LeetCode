int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxArea(int* height, int heightSize) {
    int ans = 0;
    int lp = 0, rp = heightSize - 1; //Use double pointer as mentioned in hints: use as same as the tracking of rp and lp (as given in hints)

    while(lp < rp) {
        int lval = height[lp];
        int rval = height[rp];
        int area = min(lval, rval) * (rp - lp);

        if(lval >= rval) {
            rp--;
        }
        else {
            lp++;
        }

        if(ans < area)
            ans = area;
    }

    return ans;
}
