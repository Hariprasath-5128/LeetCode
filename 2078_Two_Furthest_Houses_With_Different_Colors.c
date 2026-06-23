int maxDistance(int* colors, int colorsSize) {
    int ans = 0;

    for(int i = 0; i<colorsSize; i++){
        for(int j = i; j<colorsSize; j++){
            if(colors[i] != colors[j] && ans < abs(i-j))
                ans = abs(i-j);
        }
    }
    return ans;
}
