#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int x, y;
} Node;

bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {
    int m = gridSize;
    int n = gridColSize[0];

    int **dist = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++){
        dist[i] = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++)
            dist[i][j] = INT_MAX;
    }

    int maxSize = 2 * n * m;
    Node *dq = (Node *)malloc(sizeof(Node) * maxSize);
    int front = maxSize / 2;
    int back = front;

    dist[0][0] = grid[0][0];
    dq[back++] = (Node){0,0};

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    while(front < back){
        Node cur = dq[front++];
        int x = cur.x;
        int y = cur.y;

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            int w = grid[nx][ny];

            if(dist[x][y] + w < dist[nx][ny]){
                dist[nx][ny] = dist[x][y] + w;

                if(w == 0)
                    dq[--front] = (Node){nx, ny};
                else
                    dq[back++] = (Node){nx, ny};
            }
        }
    }

    bool ans = (dist[m-1][n-1] < health);

    for(int i = 0; i < m; i++)
        free(dist[i]);
    free(dist);
    free(dq);

    return ans;
}
