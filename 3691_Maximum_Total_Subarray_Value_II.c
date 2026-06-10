#define MAXN 100005
#define LOG 20 //Maximum no. of the digit

typedef long long ll;

int mx[MAXN][LOG];
int mn[MAXN][LOG];
int lg[MAXN];

int max(int a, int b){
    return (a > b) ? a : b;
}

int min(int a, int b){
    return (a < b) ? a : b;
}

typedef struct {
    int value;
    int l;
    int r;
} Node;

Node heap[MAXN];
int heapSize = 0;

void swap(Node* a, Node* b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Node x){
    heap[++heapSize] = x;
    int idx = heapSize;

    while(idx > 1){
        int parent = idx/2;

        if(heap[parent].value >= heap[idx].value)
            break;

        swap(&heap[parent], &heap[idx]);
        idx = parent;
    }
}

Node pop(){
    Node top = heap[1];
    heap[1] = heap[heapSize--];
    int idx = 1;

    while(1){
        int largest = idx;
        int left = 2*idx;
        int right = 2*idx + 1;

        if(left <= heapSize && heap[left].value > heap[largest].value)
            largest = left;
        
        if(right <= heapSize && heap[right].value > heap[largest].value)
            largest = right;

        if(largest == idx)
            break;
        
        swap(&heap[idx], &heap[largest]);
        idx = largest;
    }
    return top;
}

//As accessing the sparse table is 0(1), which is very easy than the segment tree - O(log n)
void buildSparseTables(int* nums, int n)
{
    //Build Log table
    lg[1] = 0;
    for(int i = 2; i<=n; i++){
        lg[i] = lg[i/2] + 1;
    }

    //Level 0
    for(int i = 0; i<n; i++){
        mx[i][0] = nums[i];
        mn[i][0] = nums[i];
    }

    //Higher Levels
    for(int j = 1; j<LOG; j++){ //Here j represent the length; like 2^j<=length of the array (n)
        for(int i = 0; i+(1<<j)<=n; i++){
            mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
            mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
        }
    }
}

int getMax(int L, int R){
    int len = R-L+1;
    int k = lg[len];

    int leftBlock = mx[L][k];
    int rightBlock = mx[R - (1<<k)+1][k];

    return max(leftBlock, rightBlock); //log[k]-defines to choose which length of array you can choose so that you can choose 2 (as the log's base is 2) precomputed array to satify the given range;
}

int getMin(int L, int R){
    int len = R - L + 1;
    int k = lg[len];

    int leftBlock = mn[L][k];
    int rightBlock = mn[R - (1 << k) + 1][k];

    return min(leftBlock, rightBlock);
}

int subarrayValue(int l, int r){
    return getMax(l, r) - getMin(l, r);
}
/*
1. Build Max Sparse Table
   → O(1) range maximum queries

2. Build Min Sparse Table
   → O(1) range minimum queries

3. For each starting index l:
   → Compute value(l, n-1)
   → Push (value, l, n-1) into a Max Heap

4. Repeat k times:
   a) Pop the largest value from the heap
   b) Add it to the answer
   c) If r > l:
      → Move to the next subarray in the same list (r--)
      → Compute value(l, r) using Sparse Tables
      → Push it back into the heap

5. After k extractions,
   → The accumulated sum is the answer.
*/

long long maxTotalValue(int* nums, int numsSize, int k) {
    int n = numsSize;

    buildSparseTables(nums, n);
    heapSize = 0;

    for(int l = 0; l<n;l++){
        Node cur;

        cur.l = l;
        cur.r = n-1;
        cur.value = subarrayValue(l, n-1);

        push(cur);
    }

    ll ans = 0;

    while(k-- && heapSize){
        Node cur = pop();

        ans+= cur.value;

        if(cur.r > cur.l){
            cur.r--;

            cur.value = subarrayValue(cur.l, cur.r);

            push(cur);
        }
    }
    return ans;
}
