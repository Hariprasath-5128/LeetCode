int max(int a, int b){
    return a > b ? a : b;
}

/*
For every two consecutive points:
(x1, y1) -> (x2, y2)

Calculate:
dx = |x2 - x1|
dy = |y2 - y1|



Movement Rules
Horizontal Move:
(x, y) -> (x+1, y)
Cost = 1 second
Vertical Move:
(x, y) -> (x, y+1)
Cost = 1 second
Diagonal Move:
(x, y) -> (x+1, y+1)
Cost = 1 second


Key Observation
A diagonal move changes BOTH x and y at the same time.

Therefore:
Use diagonal moves as much as possible.
Number of diagonal moves = min(dx, dy)
Remaining moves = max(dx, dy) - min(dx, dy)
Total Time

time =
min(dx, dy)
+
(max(dx, dy) - min(dx, dy))

= max(dx, dy)
*/

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int ans = 0; 

    //You have to visit the points in the same order as they appear in the array. So, no need to find the optimal solution

    for(int i = 1; i<pointsSize; i++){
        int dx = abs(points[i][0] - points[i-1][0]);
        int dy = abs(points[i][1] - points[i-1][1]);

        ans += max(dx, dy);
    }
    return ans;
}
