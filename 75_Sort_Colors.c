void sortColors(int* nums, int numsSize) {
    int *arr = calloc(3, sizeof(int));

    for (int i = 0; i < numsSize; i++) {//Uses counting sort; as only 0,1,2 are the array elements
        arr[nums[i]]++;
    }

    int j = 0;

    for (int i = 0; i < 3; i++) {
        while (arr[i] > 0) {
            nums[j++] = i;
            arr[i]--;
        }
    }

    free(arr);
}
