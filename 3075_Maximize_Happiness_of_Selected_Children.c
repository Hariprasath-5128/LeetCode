long long maximumHappinessSum(int* happiness, int happinessSize, int k) {

    // Sort in descending order
    int cmp(const void *a, const void *b) {
        return (*(int*)b) - (*(int*)a);
    }

    qsort(happiness, happinessSize, sizeof(int), cmp);

    int i = 0;
    long long maxHappy = 0;

    while(k != 0) {

        // If happiness becomes 0 or negative, stop
        if(happiness[i] - i <= 0) {
            break;
        }

        maxHappy += happiness[i] - i;

        k--;
        i++;
    }

    return maxHappy;
}
