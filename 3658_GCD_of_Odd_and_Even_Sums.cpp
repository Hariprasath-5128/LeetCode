class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int end = n * 2;

        int even_sum = n * (2 + end)/2;
        int odd_sum = n * (1 + end - 1)/2;

        return gcd(even_sum, odd_sum);

        //Or the total answer is entirely return(n); according to the mathematics
    }
};
