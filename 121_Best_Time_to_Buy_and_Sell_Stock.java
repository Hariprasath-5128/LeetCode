class Solution {
    public int maxProfit(int[] arr) {
       int[] diff = new int[arr.length - 1];

       for(int i = 0; i<arr.length-1; i++){
           diff[i] = arr[i+1]-arr[i];
           //System.out.println(diff[i]);
       }



       int maxSoFar = 0;
       int maxForNow = 0;
       for(int i = 0; i<arr.length - 1; i++){
           maxForNow = Math.max(maxForNow + diff[i], diff[i]);
           maxSoFar = Math.max(maxSoFar, maxForNow);
       }

       return maxSoFar > 0 ? maxSoFar:0;
    }
}
