class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        long max = 0;
        for(int i: piles)
            max = Math.max(i, max);

        //The K value will be between 1 and max(piles)
        /*
        k = 1 → false
        k = 2 → false
        k = 3 → false
        k = 4 → true
        k = 5 → true
        k = 6 → true
        ...
        Here, we need to find the where the change from false -> true takes place :: That is the answer
        */
        long right = max;
        long left = 1;
        long ans = 0;

        while(left <= right){
            long mid = left + (right - left)/2;

            long hours =  0;
            for(long i: piles)
                hours += (i + mid -1)/mid; //Returns the ceil in integer form

            if(hours <= h){
                ans = mid;
                right = mid -1;
            }
            else
                left = mid + 1;
        }

        return (int)ans;
    }
}