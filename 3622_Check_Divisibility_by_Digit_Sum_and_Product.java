class Solution {
    public boolean checkDivisibility(int n) {
        int a = n;
        int sum = 0;
        int prod = 1;

        while(a!=0){
            int digit = a % 10;
            sum += digit;
            prod *= digit;
            a/=10;
        }

        int result = sum + prod;

        return (n % result == 0) ? true:false;
    }
}
