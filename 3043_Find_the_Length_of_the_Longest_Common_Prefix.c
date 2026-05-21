int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {

    // Stores whether a prefix exists in arr1
    int *freq = calloc(100000001, sizeof(int));

    // Store all prefixes of arr1 elements
    for(int i = 0; i < arr1Size; i++) {

        int temp = arr1[i];

        while(temp > 0) {
            freq[temp] = 1;
            temp /= 10;
        }
    }

    int maxSize = 0;

    // Check prefixes of arr2 elements
    for(int i = 0; i < arr2Size; i++) {

        int temp = arr2[i];
        int len = 0;

        // Find number of digits
        int t = temp;
        while(t > 0) {
            len++;
            t /= 10;
        }

        while(temp > 0) {

            // Common prefix found
            if(freq[temp]) {

                if(len > maxSize)
                    maxSize = len;
            }

            temp /= 10;
            len--;
        }
    }

    free(freq);

    return maxSize;
}
