int bitwiseComplement(int n) {
    if (n == 0)
        return 1;

    int x = n;
    int bits = 0;

    while (x) {
        bits++;
        x >>= 1;
    }

    int mask = (1 << bits) - 1;
    return n ^ mask;
}
