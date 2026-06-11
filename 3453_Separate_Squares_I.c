#define EPS 1e-6 // as the high and low (for y-axis), can go on floating upto 5 points; we can use this like high - low > EPS;

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {

    /*
    1. Calculate total area of all squares.
    2. target = totalArea / 2.
    3. Binary search on y-coordinate.
    4. For each mid:
        find area below the line.
    5. If below area < target:
        move line up.
    6. Else:
        move line down.
    7. Return the final y-coordinate.
    */

    double totalArea = 0; 

    double low = 10000000;
    double high = 0;

    for(int i = 0; i<squaresSize; i++){
        double y = squares[i][1];
        double side = squares[i][2];

        totalArea += side*side;

        if(y<=low) //Overall bottom of the squares
            low = y;
        if(y+side >= high) //Overall top of the squares
            high = y+side;
    }

    double target = totalArea/2.0;

    while(high -low >EPS){
        double mid = (low+high)/2.0;

        double belowArea = 0.0;

        for(int i = 0; i<squaresSize; i++){
            double y = squares[i][1];
            double side = squares[i][2];

            if(y>=mid) //bottom of that squares is above the mid line
                continue;
            else if(mid >= y+side)//that whole square is below the mid line
                belowArea+= side*side;
            else //the mid line pass throught that square
                belowArea += side*(mid - y);
        }
        if(belowArea < target)
            low = mid;
        else 
            high = mid;
    }
    return high;
}
