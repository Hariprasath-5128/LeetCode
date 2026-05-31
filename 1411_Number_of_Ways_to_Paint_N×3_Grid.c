#define MOD 1000000007 //As per the question

int numOfWays(int n) {

    //As the question itself predefined only upto 3 columns, So only two types are available ABA and ABC

    //Initialising abc and aba with 6 (with the help of R,Y,G), so there is one count less in the for loop.
    long long aba = 6; // Type ABA
    long long abc = 6; // Type ABC

    for(int i = 2; i <= n; i++) {
        long long newAba = (3 * aba + 2 * abc) % MOD; //check with some example, only 3 aba and 2 abc pattern can be stacked below the current 'aba' pattern.
        long long newAbc = (2 * aba + 2 * abc) % MOD;//check with some example, only 2 aba and 2 abc pattern can be stacked below the current 'abc' pattern

        aba = newAba;
        abc = newAbc;
    }

    return (aba + abc) % MOD;
}
