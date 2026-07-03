// Among all valid paths, maximize the minimum edge -> Use binary search to find that maximum cost  

/*  

Algorithm:  

1. Build the graph using an adjacency list.  
   - Ignore edges whose destination is an offline intermediate node.  
   - Store all edge weights in an array.  
   - Compute the indegree of every node.  

2. Find the topological order of the DAG using Kahn's Algorithm.  
   - Push all nodes with indegree = 0 into a queue.  
   - Pop a node, store it in topo[].  
   - Reduce the indegree of its adjacent nodes.  
   - If any node's indegree becomes 0, push it into the queue.  

3. Sort all edge weights and remove duplicates.  

4. Perform Binary Search on the sorted edge weights.  
   - Let the current candidate minimum edge weight be limit.  

5. For each limit, perform DP on the topological order.  
   - Initialize dp[] = INF.  
   - Set dp[0] = 0.  
   - Traverse nodes in topo[].  
   - For every outgoing edge:  
       • Ignore the edge if edgeCost < limit.  
       • Otherwise update:  
         dp[v] = min(dp[v], dp[u] + edgeCost).  

6. If dp[n-1] <= k,  
      the current limit is feasible.  
      Search for a larger limit.  
   Else  
      search for a smaller limit.  

7. Return the largest feasible limit.  
   If no feasible path exists, return -1.  

*/  

typedef long long ll;  

typedef struct {  
    int to;  
    int cost;  
    int next;  
} Edge;  

#define INF ((ll)4e18)  

Edge* graph;  
int* head;  
int edgeIdx;  

// Adjacent list  
void addEdge(int u, int v, int w) {  
    graph[edgeIdx].to = v;  
    graph[edgeIdx].cost = w;  
    graph[edgeIdx].next = head[u];  
    head[u] = edgeIdx++;  
}  

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }  

bool check(int limit, int n, long long k, int* topo) {  
    ll* dp = (ll*)malloc(sizeof(ll) * n);  

    for (int i = 0; i < n; i++)  
        dp[i] = INF;  

    dp[0] = 0;  
    for (int i = 0; i < n; i++) {  
        int u = topo[i];  

        if (dp[u] == INF)  
            continue;  

        for (int e = head[u]; e != -1; e = graph[e].next) {  
            int v = graph[e].to;  
            int w = graph[e].cost;  

            if (w < limit)  
                continue;  

            if (dp[v] > dp[u] + w)  
                dp[v] = dp[u] + w;  
        }  
    }  

    bool ok = (dp[n - 1] <= k);  
    free(dp);  
    return ok;  
}  

int findMaxPathScore(int** edges, int edgesSize, int* edgesColSize,  
                     bool* online, int onlineSize, long long k) {  
    int n = onlineSize;  

    graph = (Edge*)malloc(edgesSize * sizeof(Edge));  
    head = (int*)malloc(n * sizeof(int));  

    for (int i = 0; i < n; i++)  
        head[i] = -1;  

    edgeIdx = 0;  

    int* indeg = (int*)calloc(n, sizeof(int));  

    int* vals = (int*)malloc(edgesSize * sizeof(int));  
    int cnt = 0;  

    for (int i = 0; i < edgesSize; i++) {  

        int u = edges[i][0];  
        int v = edges[i][1];  
        int w = edges[i][2];  

        if (v != n - 1 && !online[v])  
            continue;  

        addEdge(u, v, w);  

        indeg[v]++;  

        vals[cnt++] = w;  
    }  

    // Topological Order  
    int* queue = (int*)malloc(n * sizeof(int));  
    int* topo = (int*)malloc(n * sizeof(int));  

    int front = 0, rear = 0;  

    for (int i = 0; i < n; i++) {  
        if (indeg[i] == 0)  
            queue[rear++] = i;  
    }  

    int idx = 0;  
    while (front < rear) {  

        int u = queue[front++];  

        topo[idx++] = u;  

        for (int e = head[u]; e != -1; e = graph[e].next) {  

            int v = graph[e].to;  

            indeg[v]--;  

            if (indeg[v] == 0)  
                queue[rear++] = v;  
        }  
    }  

    qsort(vals, cnt, sizeof(int), cmp);  

    int m = 0;  

    // Remove the duplicates  
    for (int i = 0; i < cnt; i++) {  
        if (i == 0 || vals[i] != vals[i - 1])  
            vals[m++] = vals[i];  
    }  

    int l = 0;  
    int r = m - 1;  
    int ans = -1;  

    while (l <= r) {  

        int mid = (l + r) / 2;  

        if (check(vals[mid], n, k, topo)) {  
            ans = vals[mid];  
            l = mid + 1;  
        } else {  
            r = mid - 1;  
        }  
    }  

    free(graph);  
    free(head);  
    free(indeg);  
    free(queue);  
    free(topo);  
    free(vals);  

    return ans;  
}  
