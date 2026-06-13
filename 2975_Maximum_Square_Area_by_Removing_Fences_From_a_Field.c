#define MOD 1000000007LL

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize) {
    int H[hFencesSize + 2];
    int V[vFencesSize + 2];

    H[0] = 1;
    V[0] = 1;

    for(int i = 0; i < hFencesSize; i++)
        H[i + 1] = hFences[i];

    for(int i = 0; i < vFencesSize; i++)
        V[i + 1] = vFences[i];

    H[hFencesSize + 1] = m;
    V[vFencesSize + 1] = n;

    int hSize = hFencesSize + 2;
    int vSize = vFencesSize + 2;

    qsort(H, hSize, sizeof(int), compare);
    qsort(V, vSize, sizeof(int), compare);

    /*
        Maximum number of distances:
        602 * 601 / 2 ≈ 181000
    */

    int total = hSize * (hSize-1)/2;

    long long *dist = malloc(total * sizeof(long long));
    int idx = 0;

    // Store all horizontal distances
    for(int i = 0; i < hSize; i++){
        for(int j = i + 1; j < hSize; j++){
            dist[idx++] = (long long)H[j] - H[i];
        }
    }
    qsort(dist, idx, sizeof(long long), compare);
    long long maxSide = -1;

    for(int i = 0; i<vSize; i++){
        for(int j = i+1; j<vSize; j++){
            long long d = (long long)V[j]-V[i];

            if(bsearch(&d, dist, idx, sizeof(long long), compare)){ //binary search
                if(d > maxSide)
                    maxSide = d;
            }
        }
    }
    free(dist);

    if(maxSide == -1)
        return -1;

    return (int)((maxSide * maxSide) % MOD);
}
