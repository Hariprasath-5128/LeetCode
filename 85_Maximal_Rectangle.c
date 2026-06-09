int max(int a, int b) {
    return a > b ? a : b;
}

int largestRectangleArea(int* heights, int n){
    int stack[n+1];
    int top = -1;

    int maxArea = 0;
    //Use stack for each row's height (accumulation)...x
    for(int i = 0; i<=n; i++){
        int currHeight = (i==n) ? 0:heights[i];

        while(top != -1 && heights[stack[top]] >= currHeight){

            int height = heights[stack[top]];
            top--;

            int pse = (top == -1) ? -1:stack[top];

            int width = i - pse - 1;
            int area = height * width;

            maxArea = max(maxArea, area);
        }
        stack[++top] = i;
    }
    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if(matrixSize == 0)
        return 0;

    int cols = matrixColSize[0];

    int heights[cols];

    for(int j = 0; j < cols; j++)
        heights[j] = 0;

    int ans = 0;

    for(int i = 0; i < matrixSize; i++) {

        for(int j = 0; j < cols; j++) {

            if(matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        ans = max(ans, largestRectangleArea(heights, cols));
    }

    return ans;
}