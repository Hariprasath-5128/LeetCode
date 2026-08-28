class Solution {
    public List<Integer> getRow(int rowIndex) {
 
        //In Pascal's Triangle, the values in row n are: C(n,0),C(n,1),C(n,2),…
        //C(n,k) = n!​/k!(n−k)!
        //Divide C(n,k)/C(n,k-1) to get the prev and next relation

        List<Integer> result = new ArrayList<>();
        result.add(1);
        int prev = 1;

        for(int i = 1; i < rowIndex+1; i++){
            long next_val = (long) prev * (rowIndex - i+1)/i;
            int next = (int) next_val;
            result.add(next);
            prev = next;
        }

        return result;
    }
}