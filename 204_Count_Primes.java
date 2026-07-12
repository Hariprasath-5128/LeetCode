class Solution {
    //Simple Sieve problem
    //Use Sieve of Eratosthenes.

    public int countPrimes(int n) {
        int num = n;

        boolean[] bool = new boolean[num];

        for(int i = 2; i < bool.length; i++)
            bool[i] = true;

        for(int i = 2; i < Math.sqrt(num); i++){
            if(bool[i] == true){

                for(int j = i*i; j < num; j+=i){ //The smallest prime number
                    bool[j] = false;
                }
            }
        }

        int count = 0;
        for(int i = 2; i < bool.length; i++){
            if(bool[i] == true)
                count++;
        }

        return count;
    }
}
