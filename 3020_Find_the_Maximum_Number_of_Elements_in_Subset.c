/*

1.Count frequency of every number.
2.Handle 1 separately.
3.For every other distinct number:
    Let cur = x.
    While freq[cur] >= 2
        contribute 2
        square cur

    If the final cur exists once or more,
        add 1
    otherwise remove the last added pair (-1) because there is no center, we can add only one number from that pair.
4.Take the maximum

*/

typedef struct {
    long long key;
    int value;
    int used;
} HashNode;

#define HASH_SIZE 262144

HashNode hash[HASH_SIZE];

unsigned int hashFunc(long long x){
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    return (unsigned int)x & (HASH_SIZE - 1);
} //For hashing an integer, predefined method in HashSet

void hashClear(){
    memset(hash, 0, sizeof(hash));
}

void hashInsert(long long key){
    unsigned int idx = hashFunc(key);
    while(hash[idx].used && hash[idx].key != key)
        idx = (idx+1) & (HASH_SIZE - 1);

    if (!hash[idx].used) {
        hash[idx].used = 1;
        hash[idx].key = key;
        hash[idx].value = 1;
    } else {
        hash[idx].value++;
    }
}

int hashGet(long long key){
    unsigned int idx = hashFunc(key);
    while(hash[idx].key == key){
        if(hash[idx].key == key){
            return hash[idx].value;
        }
        idx = (idx+1) & (HASH_SIZE - 1);
    }
    return 0;
}

int maximumLength(int *nums, int numsSize){
    hashClear();

    for(int i = 0; i< numsSize; i++){
        hashInsert(nums[i]);
    }

    int ans = 1;
    int ones = hashGet(1);

    if(ones)
        ans = ones - (ones % 2 == 0);

    for(int i = 0; i < HASH_SIZE; i++){
        if(!hash[i].used)
            continue;

        long long start = hash[i].key;

        if(start == 1)
            continue;

        long long cur = start;
        int len = 0;

        while(hashGet(cur) >= 2){
            len += 2;
            cur *= cur;
        }  

        if(hashGet(cur) >= 1)
            len++;
        else
            len--;

        if(len > ans)
            ans = len; 
    }

    return ans;
}
