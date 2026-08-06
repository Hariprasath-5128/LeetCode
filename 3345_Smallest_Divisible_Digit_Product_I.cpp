class Solution {
public:
    int smallestNumber(int n, int t) {

        for(int i = n; i <= 100; i++){
            int org = i;
            int prod = 1;
            while(org != 0){
                prod *= org%10;
                org/=10;
            }

            if(prod % t == 0)
                return i;
        }
        return -1;
    }
};
