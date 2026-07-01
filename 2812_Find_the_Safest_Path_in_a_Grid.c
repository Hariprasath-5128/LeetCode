/*

Grid
│
▼
Input n × n matrix
(0 = empty cell, 1 = thief)

│
▼
Multi-source BFS
Start BFS simultaneously from every thief.
This computes the shortest distance from each cell
to its nearest thief.

│
▼
Distance Matrix
Each cell now stores its "safeness value",
i.e., the Manhattan distance to the closest thief.

Example:
2 1 0
3 2 1
4 3 2

│
▼
Modified Dijkstra (Max Heap)
Treat each distance value as the safety of that cell.
Start from (0,0) and always explore the path with the
highest current safeness first.

For every move:
newSafeness = min(currentPathSafeness,
                  nextCellDistance)

│
▼
Maximum Bottleneck Path
Among all possible paths from (0,0) to (n−1,n−1),
find the one whose minimum cell safeness is the largest.

│
▼
Return Answer
When the destination is removed from the max heap,
its safeness value is the maximum possible safeness
factor of any valid path.

*/

typedef struct {
    int r;
    int c;
} Node;

typedef struct {
    int safe;
    int r;
    int c;
} HeapNode;

typedef struct {
    Node *data;
    int front; 
    int rear;
} Queue;

void pushQueue(Queue *q, int r, int c){
    q->data[q->rear].r = r;
    q->data[q->rear].c = c;
    q->rear++;
}

Node popQueue(Queue *q){
    return q->data[q->front++];
}

bool emptyQueue(Queue *q){
    return q->front == q->rear;
}

void heapPush(HeapNode *heap, int *size, HeapNode val){
    int i = (*size)++;
    heap[i] = val;

    while(i > 0){
        int p = (i-1)/2;
        if(heap[p].safe >= heap[i].safe)
            break;

        HeapNode temp = heap[p];
        heap[p] = heap[i];
        heap[i] = temp;
        i = p;
    }
}

HeapNode heapPop(HeapNode *heap, int *size){
    HeapNode ans = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;

    while(1){
        int left = i*2 + 1;
        int right = i*2 + 2;
        int largest = i;

        if(left < *size && heap[left].safe > heap[largest].safe)
            largest = left;

        if(right < *size && heap[right].safe > heap[largest].safe)
            largest = right;

        if(largest == i)
            break;

        HeapNode temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }

    return ans;
}

int maximumSafenessFactor(int** grid, int gridSize, int* gridColSize){

    int n = gridSize;

    int **dist = malloc(n * sizeof(int *));
    int **best = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        dist[i] = malloc(n * sizeof(int));
        best[i] = malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
            best[i][j] = -1;
        }
    }

    Queue q;
    q.data = malloc(n * n* sizeof(Node));
    q.front = q.rear = 0;

    // Multi-source BFS
    // Compute the minimum Manhattan distance from every cell
    // to its nearest thief.

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(grid[i][j] == 1){
                dist[i][j] = 0;
                pushQueue(&q, i, j);
            }
        }
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!emptyQueue(&q)){
        Node cur = popQueue(&q);

        for(int k = 0; k < 4; k++){

            int nr = cur.r + dr[k];
            int nc = cur.c + dc[k];

            if(nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;

            if(dist[nr][nc] != INT_MAX)
                continue;

            dist[nr][nc] = dist[cur.r][cur.c] + 1;
            pushQueue(&q, nr, nc);
        }
    }

    // Modified Dijkstra (Maximum Bottleneck Path)
    // Find the path whose minimum cell safeness is maximum.

    //best[r][c] = The maximum possible safeness factor of any path from (0,0) to (r,c) found so far.
    HeapNode *heap = malloc(n * n * sizeof(HeapNode));
    int heapSize = 0;

    best[0][0] = dist[0][0];

    heapPush(heap, &heapSize, (HeapNode){dist[0][0], 0, 0});

    while(heapSize){
        // Current safest path discovered so far
        HeapNode cur = heapPop(heap, &heapSize);

        if(cur.safe < best[cur.r][cur.c])
            continue;

        if(cur.r == n-1 && cur.c == n-1){
            int ans = cur.safe;

            for (int i = 0; i < n; i++) {
                free(dist[i]);
                free(best[i]);
            }

            free(dist);
            free(best);
            free(q.data);
            free(heap);

            return ans;
        }

        for(int k = 0; k < 4; k++){

            int nr = cur.r + dr[k];
            int nc = cur.c + dc[k];

            if(nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;

            int newSafe = cur.safe;

            // Path safeness after moving to the next cell.
                // It becomes the minimum of:
                // 1. Current path safeness
                // 2. Next cell's safeness
                //
                // newSafe = min(cur.safe, dist[nr][nc])
            if(dist[nr][nc] < newSafe)
                newSafe = dist[nr][nc];

            if(newSafe > best[nr][nc]){

                best[nr][nc] = newSafe;

                heapPush(heap, &heapSize, (HeapNode){newSafe , nr, nc});
            }
        }
    }

    return 0;
}
