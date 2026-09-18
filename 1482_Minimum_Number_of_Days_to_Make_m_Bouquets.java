class Solution {
    public int getNumberOfBouquets(int[] bloomDay, int mid, int m, int k){
        int count = 0;
        int numberOfBouquets = 0;
        for(int i = 0; i < bloomDay.length; i++){
            if(mid >= bloomDay[i])
                count++;

            else 
                count = 0;

            if(count == k){
                count = 0;
                numberOfBouquets++;
            }
        }
        return numberOfBouquets;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        int start = 0;
        int end = 0;
        for (int day : bloomDay) {
            end = Math.max(end, day);
        }

        int minDays = -1;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(getNumberOfBouquets(bloomDay, mid, m, k) >= m){
                minDays = mid;
                end = mid - 1;
            }

            else    
                start = mid + 1;
        }

        return minDays;
    }
}