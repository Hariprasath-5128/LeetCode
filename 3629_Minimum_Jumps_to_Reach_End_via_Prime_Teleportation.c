/*

1. Compute smallest prime factors (SPF) using a sieve.
2. Factor every array value.
3. Build: prime -> indices divisible by prime
4. Run BFS from index 0.

5.From every index:
    visit i-1
    visit i+1
    if nums[i] is prime:
        visit all indices in map[nums[i]]
        clear that list (or mark the prime as used)

*/

#define MAXV 10000000

typedef struct{
    int *data;
    int size; 
    int cap;
} Vector;

typedef struct{
    int *data;
    int front, rear;
} Queue;

void push(Vector *v, int x){  //x - is the index of nums
    if(v->size == v->cap){
        v->cap = v->cap ? v->cap * 2 : 2;
        v->data = realloc(v->data, v->cap * sizeof(int));
    }
    v->data[v->size++] = x;
    //It stores like p(prime numer) = [0, 2, 1] :Belongs to which indexes
}

int minJumps(int* nums, int numsSize) {
    if(numsSize == 1)
        return 0;

    //Find Maximum value
    int maxVal = 0;
    for(int i = 0; i<numsSize; i++){
        if(nums[i] > maxVal)
            maxVal = nums[i];
    }

    // Smallest Prime Factor (SPF) - Sieve method
    int *spf = malloc((maxVal + 1) * sizeof(int));
    for (int i = 0; i <= maxVal; i++)
        spf[i] = i;

    for(int i = 2; i*i <= maxVal; i++){
        if(spf[i]==i){
            for(int j = i*i; j <= maxVal; j+=i){
                if(spf[j]==j) //If not modified from initial 
                    spf[j] = i;

            }
        }
    }

    // prime -> list of indices divisible by prime
    Vector *primeMap = calloc(maxVal + 1, sizeof(Vector));

    for(int i = 0; i<numsSize; i++){
        int x = nums[i];

        while(x > 1){
            int p = spf[x];
            push(&primeMap[p], i);

            while(x % p == 0)
                x/=p;
        }
    }

    char *visited = calloc(numsSize, sizeof(char));
    char *primeUsed = calloc(maxVal + 1, sizeof(char));

    Queue q;
    q.data = malloc(numsSize * sizeof(int));
    q.front = q.rear = 0;

    q.data[q.rear++] = 0;
    visited[0] = 1;

    int steps = 0;

    while(q.front < q.rear){
        int sz = q.rear - q.front;

        while(sz--){
            int cur = q.data[q.front++];

            if(cur == numsSize - 1){
                free(q.data);
                free(visited);
                free(primeUsed);

                for(int i = 0; i <= maxVal; i++){
                    free(primeMap[i].data);
                }

                free(primeMap);
                free(spf);

                return steps;
            }

            //Left
            if(cur > 0 && !visited[cur - 1]){
                visited[cur - 1] = 1;
                q.data[q.rear++] = cur - 1;
            }

            //Right
            if(cur + 1 < numsSize && !visited[cur + 1]){
                visited[cur+1] = 1;
                q.data[q.rear++] = cur + 1;
            }

            //Prime Teleport
            int val = nums[cur];
            if(val >= 2 && spf[val] == val && !primeUsed[val]){
                primeUsed[val] = 1; //As spf[val] == val; means val is prime number

                Vector *v = &primeMap[val];
                for(int i = 0; i < v->size; i++){
                    int nxt = v->data[i];
                    if(!visited[nxt]){
                        visited[nxt] = 1;
                        q.data[q.rear++] = nxt;
                    }
                }
            }
        }
        steps++;
    }

    free(q.data);
    free(visited);
    free(primeUsed);

    for(int i = 0; i <= maxVal; i++){
        free(primeMap[i].data);
    }
    free(primeMap);
    free(spf);

    return -1;
}
