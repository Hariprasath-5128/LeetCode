#define MOD 1000000007LL

int countZigZagArrays(int n, int l, int r) {
    int m = r - l + 1;

    if (n == 1)
        return m % MOD;

    long long up[m], down[m];

    // length = 2
    for (int i = 0; i < m; i++) {
        up[i] = i;             // number of smaller values
        down[i] = m - 1 - i;   // number of larger values
    }

    if (n == 2) {
        long long ans = 0;
        for (int i = 0; i < m; i++)
            ans = (ans + up[i] + down[i]) % MOD;
        return (int)ans;
    }

    for (int len = 3; len <= n; len++) {

        long long prefixDown[m], suffixUp[m];
        long long newUp[m], newDown[m];

        // prefix sums of down
        prefixDown[0] = down[0];
        for (int i = 1; i < m; i++)
            prefixDown[i] = (prefixDown[i - 1] + down[i]) % MOD;

        // suffix sums of up
        suffixUp[m - 1] = up[m - 1];
        for (int i = m - 2; i >= 0; i--)
            suffixUp[i] = (suffixUp[i + 1] + up[i]) % MOD;

        // transitions
        for (int i = 0; i < m; i++) {
            newUp[i] = (i > 0) ? prefixDown[i - 1] : 0;
            newDown[i] = (i < m - 1) ? suffixUp[i + 1] : 0;
        }

        // copy back
        for (int i = 0; i < m; i++) {
            up[i] = newUp[i];
            down[i] = newDown[i];
        }
    }

    long long ans = 0;
    for (int i = 0; i < m; i++)
        ans = (ans + up[i] + down[i]) % MOD;

    return (int)ans;
}
