typedef struct Edge{
    int to;
    int cost;
    struct Edge *next;
} Edge;

typedef struct{
    int dist;
    int node;
} HeapNode;

void swap(HeapNode *a, HeapNode *b){
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void push(HeapNode *heap, int *size, int dist, int node) {
    int i = (*size)++;

    heap[i].dist = dist;
    heap[i].node = node;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (heap[p].dist <= heap[i].dist)
            break;

        swap(&heap[p], &heap[i]);
        i = p;
    }
}

HeapNode pop(HeapNode *heap, int *size) {
    HeapNode ans = heap[0]; //HeapNode consists of (distance, node)

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < *size && heap[l].dist < heap[smallest].dist)
            smallest = l;

        if (r < *size && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return ans;
}

void addEdge(Edge ** graph, int u, int v, int w){
    Edge *e = malloc(sizeof(Edge));

    e->to = v;
    e->cost = w;
    e->next = graph[u];

    graph[u] = e; // graph[1] means the nodes which are adjacent to node 1 are in the form of linked list;
}

int minCost(int n, int** edges, int edgesSize, int* edgesColSize) {

    //Add all the path, original and the reversed path
    //Then use the heapTree for the extracting greedy minimum and update the remaining path (Dijistra's using Min heap)

    Edge **graph = calloc(n, sizeof(Edge *));

    for(int i = 0; i<edgesSize; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        addEdge(graph, u, v, w);
        addEdge(graph, v, u, w*2);
    }
    int * dist = malloc(sizeof(int)*n);

    for(int i = 0; i<n; i++)
        dist[i] = INT_MAX;
    
    HeapNode *heap = malloc(sizeof(HeapNode)*(3*edgesSize+5)); //here edges are doubled after including the reversed node, and for a single node it may exist with different length and has been stored in that node.
    int heapSize = 0;
    
    dist[0] = 0;
    push(heap, &heapSize, 0,0);

    while(heapSize){
        HeapNode cur = pop(heap, &heapSize);

        int d = cur.dist;
        int u = cur.node;

        if(d!=dist[u])
            continue;
        
        if(u==n-1)
            return d;
        
        for(Edge *e = graph[u]; e; e=e->next){
            int v = e->to;
            int nd = d+e->cost;

            if(nd < dist[v]){
                dist[v] = nd;
                push(heap, &heapSize, nd, v);
            }
        }
    }
    return -1;
}
