int cmp(const void *a, const void *b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {

    // If we iterate through all element, it will find the Next suitable event through the Binary Search and Using the suffixMax[i], which contains the maximum profit from that index i is used (instead of iterating for all remaining indexes)

     // Sort events based on start time
    qsort(events, eventsSize, sizeof(int*), cmp);

    // suffixMax[i] = maximum value from i to end
    int suffixMax[eventsSize];

    // Stores best future profit from each index
    suffixMax[eventsSize - 1] = events[eventsSize - 1][2];

    for(int i = eventsSize - 2; i >= 0; i--){
        suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
    }

    int ans = 0;

    for(int i = 0; i < eventsSize; i++) {

        int start = events[i][0];
        int end = events[i][1];
        int value = events[i][2];

        // Take current event alone
        ans = max(ans, value);

        // Binary search for next non-overlapping event
        int left = i + 1;
        int right = eventsSize - 1;
        int idx = -1;

        while(left <= right){

            int mid = left + (right - left) / 2;

            if(events[mid][0] > end){
                idx = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        // Add best future event
        if(idx != -1){
            ans = max(ans, value + suffixMax[idx]);
        }
    }

    return ans;
}
