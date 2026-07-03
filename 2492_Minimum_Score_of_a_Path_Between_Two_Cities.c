typedef struct Node {
    int vertex;
    int weight;
    struct Node *next;
} Node;

Node *adj[100005];

//Adjacent List
void addEdge(int u, int v, int w) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {

    for (int i = 0; i < roadsSize; i++) {
    int u = roads[i][0];
    int v = roads[i][1];
    int w = roads[i][2];

    addEdge(u, v, w);
    addEdge(v, u, w);
    }

    int visited[100005] = {0};
    int ans=INT_MAX;
    int start = 1;
    int queue[100005];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];

        Node *curr = adj[u];

        while (curr) {
            if (ans > curr->weight)
                ans = curr->weight;

            int v = curr->vertex;

            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }

            curr = curr->next;
        }
    }

    return ans;
}