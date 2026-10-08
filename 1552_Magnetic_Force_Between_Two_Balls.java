class Solution {
    private boolean canPlaceBalls(int x, int[] position, int m){
        //Initializing the first ball in the first position
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        for(int i = 1; i < position.length && ballsPlaced < m; i++){
            int currBallPos = position[i];

            if(currBallPos - prevBallPos >= x){
                ballsPlaced++;
                prevBallPos = currBallPos;
            }
        }

        return ballsPlaced == m;
    }

    public int maxDistance(int[] position, int m) {
        
        int answer = 0;
        int n = position.length;

        Arrays.sort(position);
        int low = 1;
        int high = (int) Math.ceil(position[n-1]/(m - 1.0)); // Maximum distance = If split the bucket for m balls in equal distribution

        while(low < high){
            int mid = low + (high - low)/2;

            if(canPlaceBalls(mid, position, m)){
                answer = mid;
                low = mid + 1;
            }
            else
                high = mid;
        }

        return answer;
    }
}
