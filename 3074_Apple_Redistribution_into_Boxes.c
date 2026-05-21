int cmp(const void *a, const void *b) {
    return (*(int*)b) - (*(int*)a);
}

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {

    // Sort capacities in descending order
    qsort(capacity, capacitySize, sizeof(int), cmp);

    int total = 0;

    // Total apples
    for(int i = 0; i < appleSize; i++) {
        total += apple[i];
    }

    int totalcapacity = 0;

    // Take largest boxes first
    for(int i = 0; i < capacitySize; i++) {

        totalcapacity += capacity[i];

        if(totalcapacity >= total) {
            return i + 1;
        }
    }

    return -1;
}
