typedef long long ll;

typedef struct {
    ll sum;
    int idx;
} HeapNode;

void swap(HeapNode *a, HeapNode *b){
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void push(HeapNode *heap, int *sz, ll sum, int idx){
    int i = (*sz)++;
    heap[i].sum = sum;
    heap[i].idx = idx;

    while(i>0){
        int p = (i-1)/2;

        if(heap[p].sum < heap[i].sum || (heap[p].sum == heap[i].sum && heap[p].idx < heap[i].idx))
            break; //already in proper position

        swap(&heap[p], &heap[i]);
        i = p;
    }
}

HeapNode pop(HeapNode *heap, int *sz){
    HeapNode ans = heap[0];

    heap[0] = heap[(--(*sz))];
    int i = 0;

    while(1){
        int l = 2*i+1;
        int r = 2*i+2;
        int smallest = i;

        if(l < *sz && 
           (heap[l].sum < heap[smallest].sum || 
            (heap[l].sum == heap[smallest].sum &&
              heap[l].idx < heap[smallest].idx)))
                smallest = l;

        if(r < *sz && 
           (heap[r].sum < heap[smallest].sum || 
            (heap[r].sum == heap[smallest].sum &&
              heap[r].idx < heap[smallest].idx)))
                smallest = r;

        if(smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return ans;
}

int minimumPairRemoval(int* nums, int numsSize) {

    if(numsSize <= 1)
        return 0;

    ll *val = malloc(sizeof(ll)*numsSize);
    int *prev = malloc(sizeof(int)*numsSize);
    int *next = malloc(sizeof(int)*numsSize);
    char *alive = malloc(numsSize);

    for(int i = 0; i<numsSize; i++){
        val[i] = nums[i];
        prev[i] = i - 1;
        next[i] = (i == numsSize -1) ? -1:i+1;
        alive[i] = 1;
    }

    int bad = 0;

    for(int i = 0; i<numsSize-1; i++){
        if(val[i] > val[i+1])
            bad++;
    }

    HeapNode *heap = malloc(sizeof(HeapNode)*(3*numsSize));
    int sz = 0;

    for(int i = 0; i<numsSize-1; i++)
        push(heap, &sz, val[i]+val[i+1], i);

    int ans = 0;

    while(bad > 0){
        HeapNode cur;

        while(1){
            cur = pop(heap, &sz);

            int i = cur.idx;
            int j = next[i];

            if(alive[i] && j!=-1 && alive[j] && val[i]+val[j]==cur.sum)
                break; //valid index 
        }

        int i = cur.idx;
        int j = next[i];

        int L = prev[i];
        int R = next[j];

        //Before removing the adjacent pair and merging their sum, we are removing the invalid comparison on that particular region alone ; Range : [L, i, j, R]
        if(L!=-1 && val[L]>val[i]) bad--;
        if(val[i]>val[j]) bad--;
        if(R!=-1 && val[j] > val[R]) bad--;

         val[i] += val[j];

        alive[j] = 0;
        next[i] = R;

        if(R!=-1)
            prev[R] = i;

        if(L!=-1 && val[L] > val[i]) bad++;
        if(R!=-1 && val[i] > val[R]) bad++;

        if(L!=-1)
            push(heap, &sz, val[L]+val[i], L);

        if(R!=-1)
            push(heap, &sz, val[i]+val[R], i);

        ans++;
    }
    free(val);
    free(prev);
    free(next);
    free(alive);
    free(heap);

    return ans;
}