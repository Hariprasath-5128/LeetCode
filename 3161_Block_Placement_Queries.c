/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int max(int a, int b) {
    return a > b ? a : b;
}

typedef struct {
    int n;
    int *tree;
} SegmentTree;

void build(SegmentTree *st, int node, int l, int r, int *arr){
    if(l==r){
        st->tree[node] = arr[l];
        return;
    }

    int mid = (l+r)/2;
    build(st, node*2, l, mid, arr);
    build(st, node*2+1, mid+1, r, arr);

    st->tree[node] = max(st->tree[node*2], st->tree[node*2 + 1]);
}

void update(SegmentTree *st, int node, int l, int r, int idx, int val){

    if(l == r){
        st->tree[node] = val;
        return;
    }

    int mid = (l+r)/2;

    if(idx<=mid)
        update(st, node*2, l, mid, idx, val);
    else
        update(st, node*2+1, mid+1, r, idx, val);

    st->tree[node] = max(st->tree[node*2], st->tree[node*2 + 1]);
}

int query(SegmentTree *st, int node, int l, int r, int ql, int qr){
    if (qr < l || r < ql){
        return 0;
    }

    if (ql <= l && r <= qr){
        return st->tree[node];
    }

    int mid = (l + r) / 2;

    return max(query(st, node*2, l, mid, ql, qr), query(st, node*2+1, mid+1, r, ql, qr));
}

 int lowerBound(int *arr, int n, int target) {
    int l = 0, r = n;

    while (l < r) {
        int mid = (l + r) / 2;

        if (arr[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }

    return l;
}

int cmp(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

bool* getResults(int** queries, int queriesSize, int* queriesColSize, int* returnSize) {

    int m = 0;

    for(int i = 0; i<queriesSize; i++){
        if(queries[i][0]==2){
            m++;
        }
    }

    bool *ans = malloc(sizeof(bool)*m); // For storing the answer

    int *coord = malloc(sizeof(int)*(queriesSize+1));
    int coordSize = 0;

    coord[coordSize++] = 0;

    for (int i = 0; i < queriesSize; i++)
        coord[coordSize++] = queries[i][1];

    qsort(coord, coordSize, sizeof(int), cmp);

    int uniqueSize = 0;


    for(int i = 0; i<coordSize; i++){   //For storing the unique block coordinate; coord - storing the unique coordinates of the blocks
        if(i==0||coord[i]!=coord[i-1]){
            coord[uniqueSize++] = coord[i];
        }
    }

    coordSize = uniqueSize;

    bool *active = calloc(coordSize, sizeof(bool)); // active - Here, we are doing the reverse processing, first we will add all the obstacles and then we will process each query in a reversed manner. It is the optimised way as it has the less no. of steps.

    //Initializing all as TRUE in active, as we are processing from reversed position. Only for the query type = 1;
    active[0] = true;

    for(int i = 0; i < queriesSize; i++) {
        if(queries[i][0] == 1) {
            int idx = lowerBound(coord, coordSize, queries[i][1]);

            active[idx] = true;
        }
    }

    int *prev = malloc(sizeof(int) * coordSize);
    int *next = malloc(sizeof(int) * coordSize);

    //Build the connection (Prev and Next) for those who are active;
    int last = -1;

    for(int i = 0; i < coordSize; i++) {

        if(!active[i]) {
            prev[i] = next[i] = -1;
            continue;
        }

        prev[i] = last;

        if(last != -1)
            next[last] = i;

        last = i;
    }

    if(last != -1)
        next[last] = -1;

    int *gap = calloc(coordSize, sizeof(int));//stores the gap between the consective blocks;

    for(int i = 0; i<coordSize; i++){

        if(!active[i] || prev[i] == -1)
            continue;

        gap[i] = coord[i]-coord[prev[i]];
    }

    SegmentTree st;
    st.n = coordSize;
    st.tree = calloc(coordSize*4, sizeof(int));

    build(&st, 1,0,coordSize-1, gap);
    int answerIndex = m-1;

    for(int q = queriesSize -1; q>=0; q--){
        if(queries[q][0] == 2){
            int x = queries[q][1];
            int sz = queries[q][2];

            int idx = lowerBound(coord, coordSize, x); 
            
            /*
            * lowerBound gives the first coordinate >= x.
            * This loop moves to the largest compressed coordinate <= x.
            */
            
            while(idx+1 < coordSize && coord[idx+1]<=x)
                idx++;

            while(!active[idx])
                idx--;
            //Here, we will navigate to the ACTIVE obstacle ≤ x. Useful for calculating the Tailgap;

            int bestGap = query(&st, 1, 0,coordSize - 1, 0, idx);
            int tailGap = x - coord[idx];

            ans[answerIndex--] = max(bestGap, tailGap) >= sz;
        }
        else{
            int idx = lowerBound(coord, coordSize, queries[q][1]);

            int p = prev[idx];
            int n = next[idx];

            if(n != -1){
                gap[n] = coord[n] - coord[p];
                update(&st, 1, 0, coordSize-1, n, gap[n]);
            }

            update(&st, 1, 0, coordSize-1, idx, 0);

            if(p != -1)
                next[p] = n;

            if(n!=-1){
                prev[n] = p;
            }
            active[idx] = false;
        }
    }
    free(coord);
    free(active);
    free(prev);
    free(next);
    free(gap);
    free(st.tree);

    *returnSize = m;
    return ans;
}