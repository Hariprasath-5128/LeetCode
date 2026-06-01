#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int minimumCost(int* cost, int costSize) {
    qsort(cost, costSize, sizeof(int), compare);

    int ans = 0;

    for (int i = 0; i < costSize; i++) {
        if (i % 3 != 2)
            ans += cost[i];
    }

    return ans;
}
