/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdlib.h>
 #define Tab 10007

 typedef struct {
    int key;   
    int index;  
    int used;    
} HashEntry;

int hash(int key){
    return(key%Tab + Tab)%Tab;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    HashEntry* table = (HashEntry*)calloc(Tab, sizeof(HashEntry));
    for(int i = 0; i<numsSize; i++){
        int comp = target-nums[i];
        int h = hash(comp);

        while(table[h].used){
            if(comp == table[h].key){
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = table[h].index;
                result[1] = i;
                *returnSize = 2;
                free(table);
                return result;
            }
            h = (h+1)%Tab;
        }
        h = hash(nums[i]);
        while(table[h].used){
            h = (h+1)%Tab;
        }
        table[h].key = nums[i];
        table[h].index = i;
        table[h].used = 1;
    }
    *returnSize = 0;
    free(table);
    return NULL;
                           
}