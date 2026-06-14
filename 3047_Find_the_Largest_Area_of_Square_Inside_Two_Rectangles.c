int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}


long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {

    long long maxArea = 0;

    for(int i = 0; i < bottomLeftSize; i++){
        for(int j = i+1; j < bottomLeftSize; j++){
            if(i!=j){
                int left = max(bottomLeft[i][0], bottomLeft[j][0]);
                int right = min(topRight[i][0], topRight[j][0]);

                int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                int top = min(topRight[i][1], topRight[j][1]);

                int width = right-left;
                int height = top-bottom;

                if(width <=0 || height <=0){
                    //No intersection
                    continue;
                }
                int side = min(width, height);
                long long area = 1LL*side*side; //generally side*side (produce int, which can overflow); so multiply by (long long) type for the type promotion

                if(maxArea < area)
                    maxArea = area;
            }
        }
    }
    return maxArea;
}