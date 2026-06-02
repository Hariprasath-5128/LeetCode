#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize,
                       int* landDuration, int landDurationSize,
                       int* waterStartTime, int waterStartTimeSize,
                       int* waterDuration, int waterDurationSize) {
    int ans = INT_MAX;

    for (int i = 0; i < landStartTimeSize; i++) {
        for (int j = 0; j < waterStartTimeSize; j++) {

            // LAND -> WATER
            int landFinish = landStartTime[i] + landDuration[i];
            int startWaterTime = max(landFinish, waterStartTime[j]);
            int finish1 = startWaterTime + waterDuration[j];

            // WATER -> LAND
            int waterFinish = waterStartTime[j] + waterDuration[j];
            int startLandTime = max(waterFinish, landStartTime[i]);
            int finish2 = startLandTime + landDuration[i];

            if (finish1 < ans) ans = finish1;
            if (finish2 < ans) ans = finish2;
        }
    }

    return ans;
}
