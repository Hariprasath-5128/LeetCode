/*
Path:
1 ---- A ---- B
Two edges.

Possible assignments:
1 1  -> 2 (even)
1 2  -> 3 (odd)
2 1  -> 3 (odd)
2 2  -> 4 (even)

Total assignments = 4
Valid assignments = 2

Pattern:
| Depth d | Total Assignments | Odd Cost Assignments |
| ------- | ----------------- | -------------------- |
| 1       | 2                 | 1                    |
| 2       | 4                 | 2                    |
| 3       | 8                 | 4                    |
| 4       | 16                | 8                    |

*/

#define MOD 1000000007LL

//Fast exponention; for example 2^50 takes 50 steps, but fast exp- take 5 to 7 steps, which is very faster

long long modPow(long long base, long long exp){

/*
Now:
2^50: 50 = 32 + 16 + 2

Binary representation:
50 = 110010₂
     ↑↑  ↑
     ||  |
     ||  +---- 2^1 = 2
     |+------- 2^4 = 16
     +--------- 2^5 = 32

Therefore:

2^50
= 2^(32 + 16 + 2)
= 2^32 × 2^16 × 2^2

The algorithm builds:

2^1  = 2
2^2  = 4
2^4  = 16
2^8  = 256
2^16 = 65536
2^32 = 4294967296

Then it looks at the binary form of 50: 110010₂
Bits that are 1 correspond to:32, 16, and 2

So it multiplies: 2^32 × 2^16 × 2^2
= 2^(32 + 16 + 2)
= 2^50
*/

    long long result = 1;

    while(exp > 0){
        if(exp & 1)
            result = (result*base)%MOD;
        
        base = (base*base)%MOD;
        exp>>=1;
    }
    return result;
}

int maxDepth = 0;

void dfs(int node, int parent, int depth, int** adj, int* size){
    if(depth > maxDepth)
        maxDepth = depth;

    for(int i = 0; i<size[node]; i++){
        int next = adj[node][i];

        if(next != parent)
            dfs(next, node, depth+1, adj, size);
    }
}

int assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;

    int* degree = calloc(n+1, sizeof(int));

    for(int i = 0; i< edgesSize; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        degree[u]++;
        degree[v]++;
    }

    int** adj = malloc((n + 1) * sizeof(int*));
    int* size = calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++)
        adj[i] = malloc(degree[i] * sizeof(int));

    for(int i = 0; i<edgesSize; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }
    maxDepth = 0;
    dfs(1, 0, 0, adj, size);

    long long ans = modPow(2, maxDepth - 1);

    for (int i = 1; i <= n; i++)
        free(adj[i]);

    free(adj);
    free(size);
    free(degree);

    return (int)ans;
}
