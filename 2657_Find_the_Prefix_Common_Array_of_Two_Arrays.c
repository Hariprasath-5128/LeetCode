/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {

    int size = ASize;

    // freq[x] stores how many times x appeared
    // Since arrays are permutations, max frequency is 2
    int freq[size + 1];

    int *ans = malloc(sizeof(int) * size);

    *returnSize = size;

    // Initialize frequency array
    for(int i = 0; i <= size; i++){
        freq[i] = 0;
    }

    int common = 0;

    for(int i = 0; i < size; i++){

        // Add current elements from both arrays
        freq[A[i]]++;
        freq[B[i]]++;

        // If same number occurs in both arrays at same index,
        // it directly becomes common
        if(A[i] == B[i]){
            common++;
        }
        else{

            // Frequency becomes 2 only when
            // the number is seen in both arrays
            if(freq[A[i]] == 2)
                common++;

            if(freq[B[i]] == 2)
                common++;
        }

        ans[i] = common;
    }

    return ans;
}
