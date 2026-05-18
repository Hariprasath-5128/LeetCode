//https://chatgpt.com/share/6a0a9f71-d138-8322-8eea-5c21123b2068

int front = 0;
int rear = 0;

void enqueue(int* queue, int value)
{
    queue[rear++] = value;
}

int dequeue(int* queue)
{
    return queue[front++];
}

int length()
{
    return rear - front;
}

// structure for value + original index
typedef struct{
    int value;
    int index;
}Pair;

// comparator for qsort
int cmp(const void* a, const void* b)
{
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;

    return p1->value - p2->value;
}

int minJumps(int* arr, int arrSize)
{
    if(arrSize == 1){
        return 0;
    }

    front = 0;
    rear = 0;

    // build pair array
    Pair pairs[arrSize];

    for(int i = 0; i < arrSize; i++){
        pairs[i].value = arr[i];
        pairs[i].index = i;
    }

    // sort by value
    qsort(pairs, arrSize, sizeof(Pair), cmp);

    // start/end positions for same values
    int start[arrSize];
    int end[arrSize];

    for(int i = 0; i < arrSize; i++){
        start[i] = -1;
        end[i] = -1;
    }

    // group same values
    int i = 0;

    while(i < arrSize){

        int j = i;
        while(j + 1 < arrSize && pairs[j + 1].value == pairs[i].value){
            j++;
        }

        for(int k = i; k <= j; k++){
            start[k] = i;
            end[k] = j;
        }
        i = j + 1;
    }

    // map original index -> sorted position
    int pos[arrSize];

    for(int i = 0; i < arrSize; i++){
        pos[pairs[i].index] = i;
    }

    int visited[arrSize];

    for(int i = 0; i < arrSize; i++){
        visited[i] = 0;
    }

    int processed[arrSize];

    for(int i = 0; i < arrSize; i++){
        processed[i] = 0;
    }

    int queue[arrSize];

    enqueue(queue, 0);

    visited[0] = 1;

    int steps = 0;
    int size = length();

    while(length() > 0){

        int ind = dequeue(queue);

        if(ind == arrSize - 1){
            return steps;
        }
        // RIGHT
        if(ind + 1 < arrSize && visited[ind + 1] == 0){
            enqueue(queue, ind + 1);
            visited[ind + 1] = 1;
        }
        // LEFT
        if(ind - 1 >= 0 && visited[ind - 1] == 0){
            enqueue(queue, ind - 1);
            visited[ind - 1] = 1;
        }
        // process same values only once
        int p = pos[ind];

        if(processed[p] == 0){

            for(int k = start[p]; k <= end[p]; k++){
                int nextIndex = pairs[k].index;
                if(visited[nextIndex] == 0){
                    enqueue(queue, nextIndex);
                    visited[nextIndex] = 1;
                }
            }

            for(int k = start[p]; k <= end[p]; k++){
                processed[k] = 1;
            }
        }

        size--;
        if(size == 0){
            steps++;
            size = length();
        }
    }
    return -1;
}