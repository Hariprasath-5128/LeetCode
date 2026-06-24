#define MOD 1000000007LL
typedef long long ll;

typedef struct{
    int size;
    ll a[150][150];
} Matrix;

Matrix multiply(Matrix* A, Matrix *B){
    int n = A->size;
    Matrix C;
    C.size = n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            C.a[i][j] = 0;
        }
    }

    for(int i = 0; i<n; i++){
        for(int k = 0; k<n; k++){
            if(A->a[i][k] == 0) continue;

            for(int j = 0; j<n; j++){
                if(B->a[k][j]==0) continue;

                C.a[i][j] = (C.a[i][j] + A->a[i][k] * B->a[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix base, long long exp){
    int n = base.size;
    Matrix res;
    res.size = n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            res.a[i][j] = (i==j); //creates identity matrix
        }
    }

    //We use binary exponention to compute the power faster
    while (exp > 0){
        if(exp & 1){
            res = multiply(&res, &base); //I*A = A
        }

        base = multiply(&base, &base);
        exp >>= 1;
    }
    return res;
}

int zigZagArrays(int n, int l, int r) {
    int m = r-l+1;

    if(n==1)
        return m % MOD;   

    int sz = 2*m;

    Matrix T; 
    T.size = sz;

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            T.a[i][j] = 0;
        }
    }

    //down[u] -> up[v], u<v
    //Check the down and up definition in Prob. no: 3699
    for(int u = 0; u<m; u++){
        for(int v = u+1; v<m; v++){
            T.a[v][m+u] = 1;
        }
    }

    // up[u] -> down[v], u>v
    for(int u = 0; u<m; u++){
        for(int v = 0; v<u; v++){
            T.a[m+v][u] = 1;
        }
    }

    ll state[150]; //It defines the length = 2 [up[0], up[1], down[0], down[1]]

    // length = 2
    for (int v = 0; v < m; v++) {
        state[v] = v;              // up[v]
        state[m + v] = m - 1 - v;  // down[v]
    }
    //state - first half up->transition, second half down->transition

       /*  possible states, with m = 3 (values = 0,1,2)

                    Columns (source)
                    u0  u1  u2  d0  d1  d2
        Rows
        (dest)

        u0 (0)        0   0   0   0   0   0

        u1 (1)        0   0   0   1   0   0

        u2 (2)        0   0   0   1   1   0

        d0 (3)        0   1   1   0   0   0

        d1 (4)        0   0   1   0   0   0

        d2 (5)        0   0   0   0   0   0
    */


    if(n > 2){
        Matrix P = power(T, n-2); 
        /*

        Here, we are going to use the Math:
        State(n+1) = T * State(n)

        (or)

        State(n+1) = T^(n-1) * State(1) ; So, we are going to use the matrix multiplications.

        For our solution, if n = 5;
        Transitions are : state₂ --T--> state₃ --T--> state₄ --T--> state₅, (T-matrix shows the valid transitions from the previous state)
        Total of : n-2 transitions

        So, our solutions: State(n) = T^(n-2)*State(2) ; where State(2) is default
        This is linear recurrance.
        */

        ll nextState[150];

        for(int i = 0; i<sz; i++){
            nextState[i] = 0;

            for(int j = 0; j<sz; j++){
                nextState[i] = (nextState[i] + P.a[i][j] * state[j]) % MOD;
            }
        }

        for(int i = 0; i<sz; i++){
            state[i] = nextState[i];
        }
    }

    long long ans = 0;
    for (int i = 0; i < sz; i++)
        ans = (ans + state[i]) % MOD;

    return (int)ans;
}