typedef struct {
    int start;
    int duration;
} Ride;

int cmpRide(const void *a, const void *b){
    Ride *r1 = (Ride *)a;
    Ride *r2 = (Ride *)b;

    return r1->start - r2->start;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int query(Ride *rides, int size, int *prefixMinDuration, int *suffixMinFinish, int finishTime){
    int left = 0; 
    int right = size - 1;
    int pos = -1;

    //Last ride with start <= finishTime
    while(left <= right){
        int mid = left + (right - left)/2;

        if(rides[mid].start <= finishTime){
            pos = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    int ans = INT_MAX;

    //Already - open rides
    if(pos >=0)
        ans = min(ans, finishTime + prefixMinDuration[pos]);

    //Not yet - open rides
    if(pos < size - 1)
        ans = min(ans, suffixMinFinish[pos + 1]);
    
    return ans;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    
    Ride *land = malloc(sizeof(Ride) * landStartTimeSize);
    Ride *water = malloc(sizeof(Ride) * waterStartTimeSize);

    for(int i = 0; i<landStartTimeSize; i++){
        land[i].start = landStartTime[i];
        land[i].duration = landDuration[i];
    }

    for (int i = 0; i < waterStartTimeSize; i++) {
        water[i].start = waterStartTime[i];
        water[i].duration = waterDuration[i];
    }

    qsort(land, landStartTimeSize, sizeof(Ride), cmpRide);
    qsort(water, waterStartTimeSize, sizeof(Ride), cmpRide);

    int *waterPrefixMinDuration = malloc(sizeof(int) * waterStartTimeSize);  //Upto the index i, which is the minimum; here we are using water ride as binary search -> searching only the minimum of duration.
    int *waterSuffixMinFinish = malloc(sizeof(int) * waterStartTimeSize);   //After the index i, which is the minimum; here we are using water ride as binary search -> searching only the minimum of finish (waterStartTime + waterDuration) as the finish1 is not required.

    waterPrefixMinDuration[0] = water[0].duration;

    for(int i = 1; i<waterStartTimeSize; i++){
        waterPrefixMinDuration[i] = min(waterPrefixMinDuration[i-1], water[i].duration);
    }

    waterSuffixMinFinish[waterStartTimeSize - 1] = water[waterStartTimeSize - 1].start + water[waterStartTimeSize - 1].duration;

    for(int i = waterStartTimeSize - 2; i>=0; i--){
        int val = water[i].start + water[i].duration;

        waterSuffixMinFinish[i] = min(val, waterSuffixMinFinish[i+1]);
    }

    int *landPrefixMinDuration =
        malloc(sizeof(int) * landStartTimeSize);
    int *landSuffixMinFinish =
        malloc(sizeof(int) * landStartTimeSize);

    landPrefixMinDuration[0] = land[0].duration;

    for (int i = 1; i < landStartTimeSize; i++) {
        landPrefixMinDuration[i] =
            min(landPrefixMinDuration[i - 1],
                land[i].duration);
    }

    landSuffixMinFinish[landStartTimeSize - 1] =
        land[landStartTimeSize - 1].start +
        land[landStartTimeSize - 1].duration;

    for (int i = landStartTimeSize - 2; i >= 0; i--) {
        int val = land[i].start + land[i].duration;

        landSuffixMinFinish[i] =
            min(val,
                landSuffixMinFinish[i + 1]);
    }

    //For any finish1, we are going to set boundary on the water ride,
    // i) Less than finish1, so the final time = finish1 + waterDuration -> Use prefixMin
    // ii) Greater than finish1, so the final time = waterStartTime + waterDuration -> use SuffixMin

    int ans = INT_MAX;

    //LAND -> WATER
    for (int i = 0; i < landStartTimeSize; i++) {

        int finishLand =
            land[i].start + land[i].duration;

        ans = min(ans,
                  query(water, waterStartTimeSize, waterPrefixMinDuration,waterSuffixMinFinish, finishLand));
    }

    // WATER -> LAND
    for(int i = 0; i<waterStartTimeSize; i++){
        //also finish1
        int finishWater = water[i].start + water[i].duration;

        ans = min(ans, query(land, landStartTimeSize, landPrefixMinDuration, landSuffixMinFinish, finishWater));
    }
    free(land);
    free(water);

    free(waterPrefixMinDuration);
    free(waterSuffixMinFinish);

    free(landPrefixMinDuration);
    free(landSuffixMinFinish);

    return ans;
}