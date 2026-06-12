/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MOD 1000000007LL
#define LOG 18

int **adj;
int *adjSize;

int up[100001][LOG]; //up[node][level]
int depth[100001];

/*
Tree:
1
|
2
|
4
|
8

Node = 8
j      value      meaning
-------------------------
0        4        1 step up
1        2        2 steps up
2        0        4 steps up
3        0        8 steps up
*/

void dfs(int node, int parent){
    up[node][0] = parent;
    
    for(int j = 1; j<LOG; j++){
        if(up[node][j-1] != 0)
            up[node][j] = up[up[node][j-1]][j-1];
    }

    for(int i = 0; i< adjSize[node]; i++){
        int next = adj[node][i];

        if(next == parent)
            continue;

        depth[next]= depth[node]+1;

        dfs(next, node);
    }
}

int getLCA(int u, int v){
    if(depth[u] < depth[v])
    {
        int temp = u;
        u = v;
        v = temp;
    }

    int diff = depth[u] - depth[v];

    //if the difference in level is 13-1101; it will iterate from 18 then if it comes to 3; 1101 & 1000 = 1 (true, if passes), it goes upper level (by j levels), then 4 times and finally 1 times; where 8+4+1 = 13 times

    for(int j = LOG-1; j>=0; j--){
        if(diff & (1<<j))
            u = up[u][j]; 
    } // this loop trying to make the both u and v at the same level;

    if(u==v)
        return u;

    for(int j = LOG-1; j>=0; j--){
        if(up[u][j]!=up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }//this loop , when they (u and v) have same ancestors in jth level above, then it tries until the different ancestors;

    /*
    If ancestors are different:
        Move both upward.

    If ancestors are same:
        Don't move.
        Otherwise you'll cross the LCA.

    The loop finishes with:
        u and v sitting exactly one level below the LCA.
    */
    return up[u][0];
}

int* assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = edgesSize + 1;

    memset(up, 0, sizeof(up));
    memset(depth, 0, sizeof(depth));

    int *degree = calloc(n+1, sizeof(int));

    for(int i = 0; i<edgesSize; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        degree[u]++;
        degree[v]++;
    }

    adj = malloc((n+1)* sizeof(int*));
    adjSize = calloc(n+1, sizeof(int));

    for(int i = 1; i<=n; i++)
        adj[i] = malloc(degree[i]*sizeof(int));

    for(int i =0; i<edgesSize; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }
    depth[1] = 0;
    dfs(1,0);

    long long *pow2 = malloc((n + 1) * sizeof(long long));
    pow2[0] = 0;

     for(int i = 1; i <= n; i++) //using the precomputed value; upto the length n
    {
        if(i == 1)
            pow2[i] = 1;
        else
            pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    int *answer = malloc(queriesSize * sizeof(int));

    for(int i = 0; i<queriesSize; i++){
        int u = queries[i][0];
        int v = queries[i][1];

        int lca = getLCA(u,v);

        int len = depth[u]+depth[v]-2*depth[lca]; //maths; try with any tree

        if(len == 0)
            answer[i] = 0;
        else
            answer[i] = (int)pow2[len];
    }

    for(int i = 1; i <= n; i++)
        free(adj[i]);

    free(adj);
    free(adjSize);
    free(degree);
    free(pow2);

    *returnSize = queriesSize;
    return answer;
}