//Using hashTable (seperate chaining - going linked list for the same index key)

typedef struct Node{
    int key;
    int *indices;
    int size; 
    int cap;
    struct Node *next;
} Node;

#define HASH_SIZE 100003

Node *hash[HASH_SIZE];

int hashFunc(int x){
    return((unsigned int)x) % HASH_SIZE;
}

Node *findNode(int key){
    int h = hashFunc(key);
    Node *cur = hash[h];

    while(cur){
        if(cur->key == key)
            return cur;
        cur = cur->next;
    }

    return NULL;
}

Node *insertNode(int key){
    int h = hashFunc(key);

    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->size = 0;
    node->cap = 4;
    node->indices = (int *)malloc(sizeof(int) * node->cap);

    node->next = hash[h];
    hash[h] = node;

    return node;
}

void addIndex(Node *node, int idx){
    if(node->size == node->cap){
        node->cap *= 2;
        node->indices = (int *)realloc(node->indices, node->cap * sizeof(int));
    }

    node->indices[node->size++] = idx;
}

int minimumDistance(int* nums, int numsSize) {
    memset(hash, 0, sizeof(hash));

    for(int i = 0; i < numsSize; i++){
        Node *node = findNode(nums[i]);

        if(!node)
            node = insertNode(nums[i]);

        addIndex(node, i);
    }

    int ans = INT_MAX;

    for(int i = 0; i < HASH_SIZE; i++){
        Node *node = hash[i];

        while(node){
            if(node->size >= 3){

                for(int j = 0; j+2 < node->size; j++){
                     int dist = 2 * (node->indices[j + 2] - node->indices[j]); // i<j<k; so the dist = (j-i)+(k-j)+(k-i) = (2*(k-i))

                     if(dist < ans)
                        ans = dist;
                }
            }

            node = node->next;
        }
    }
    return ans == INT_MAX ? -1:ans;
}
