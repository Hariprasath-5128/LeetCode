long long fuel;

long long dfs(int node, int parent, int** adj, int* adjSize, int seats){
    long long people = 1;
    for(int i = 0; i<adjSize[node]; i++){
        int next = adj[node][i];
        if(parent == next) continue;

        long long childpeople = dfs(next, node, adj, adjSize, seats);
        long long cars = (childpeople+seats-1)/seats;  //ceil op  - use this formula which approxiamte for the current parent chlid.
        fuel+=cars;
        people+=childpeople;
    }
    return people;
}

long long minimumFuelCost(int** roads, int roadsSize, int* roadsColSize, int seats) {

    /*  int n = roadsSize + 1;

    // adjacency list
    int** adj = (int**)malloc(sizeof(int*) * n);
    int* adjSize = (int*)calloc(n, sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    for(int i=0;i<n;i++)
        adj[i] = (int*)malloc(sizeof(int)*n);

    // fill graph
    for(int i=0;i<roadsSize;i++){
        int a = roads[i][0];
        int b = roads[i][1];

        adj[a][adjSize[a]++] = b;
        adj[b][adjSize[b]++] = a;
    }

    // DFS to count nodes in branch
    int dfs(int node){
        visited[node] = 1;
        int count = 1;

        for(int i=0;i<adjSize[node];i++){
            int next = adj[node][i];
            if(!visited[next])
                count += dfs(next);
        }
        return count;
    }

    long long totalFuel = 0;
    visited[0] = 1;   // capital

    // check each branch from capital
    for(int i=0;i<adjSize[0];i++){
        int next = adj[0][i];

        if(!visited[next]){
            int count = dfs(next);

            long long res = 0;

            long long q = count / seats;
            long long rem = count % seats;

            long long q1 = q;

            while(q1-1 >= 0){
                res += q1 * seats;
                q1--;
            }

            res = res + rem*q + rem;

            totalFuel += res;
        }
    }

    return totalFuel; */  /*Fails if any other nodes other than 0 contains two or more nodes*/
    
    int n = roadsSize + 1;
    fuel = 0;

    // 🔴 NEW: count degree to avoid memory limit exceeded
    int* degree = (int*)calloc(n,sizeof(int));
    for(int i=0;i<roadsSize;i++){
        degree[roads[i][0]]++;
        degree[roads[i][1]]++;
    }

    // adjacency list
    int** adj = (int**)malloc(sizeof(int*) * n);
    int* adjSize = (int*)calloc(n, sizeof(int));

    // 🔴 FIX: allocate only required memory (O(n), not O(n²))
    for(int i=0;i<n;i++)
        adj[i] = (int*)malloc(sizeof(int)*degree[i]);

    // build graph
    for(int i=0;i<roadsSize;i++){
        int a = roads[i][0];
        int b = roads[i][1];

        adj[a][adjSize[a]++] = b;
        adj[b][adjSize[b]++] = a;
    }

    dfs(0, -1, adj, adjSize, seats);

    return fuel;
}
