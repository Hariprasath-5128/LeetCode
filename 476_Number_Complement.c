int findComplement(int num) {
    int n = num;

    if (n == 0)
        return 1;

    int x = n;
    int bits = 0;

    while(x != 0){
        bits++;
        x >>= 1;
    }
    unsigned int mask = (1U << bits) - 1; // makes all bits with same size as 1; for 5-101 -> 111 (mask)

    int complement = n ^ mask;

    return complement;
}
