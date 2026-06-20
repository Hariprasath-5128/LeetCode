int cmp(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[0] - y[0];
}

int maxBuilding(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize) {

    restrictions = realloc(restrictions, (restrictionsSize+2)*sizeof(int*));   //For adding the first and last boundaries 

    restrictions[restrictionsSize] = malloc(2 * sizeof(int));
    restrictions[restrictionsSize][0] = 1;
    restrictions[restrictionsSize][1] = 0; 

    restrictions[restrictionsSize + 1] = malloc(2 * sizeof(int));
    restrictions[restrictionsSize + 1][0] = n;
    restrictions[restrictionsSize + 1][1] = n-1; 

    restrictionsSize += 2;
    
    qsort(restrictions, restrictionsSize, sizeof(int *), cmp);

    //Left to right Pass - make the forwarding direction path under the given constraints; [(1,0), (2,10)] -> [(1,0), (2,1)]
    for(int i = 1; i<restrictionsSize; i++){
        int dist = restrictions[i][0] - restrictions[i-1][0];
        int maxH = restrictions[i-1][1] + dist;

        if(restrictions[i][1] > maxH)
            restrictions[i][1] = maxH;
    }

    //Right to Left Pass - make the Backward direction path under the given constraints; [(3,10), (5,1)] -> [(3,3), (5,1)]
    for(int i = restrictionsSize - 2; i>=0; i--){
        int dist = restrictions[i+1][0] - restrictions[i][0];
        int maxH = restrictions[i+1][1] + dist;

        if(restrictions[i][1] > maxH)
            restrictions[i][1] = maxH;
    }

    int ans = 0;

    for (int i = 1; i < restrictionsSize; i++) {
        int dist = restrictions[i][0] - restrictions[i - 1][0];
        int h1 = restrictions[i - 1][1];
        int h2 = restrictions[i][1];

        int peak = (h1 + h2 + dist) / 2; //Use this formula to find the peak between two restrictions.

        if (peak > ans)
            ans = peak;
    }
    return ans;
}