/*int minMoves(int* nums, int numsSize, int limit) {
    int n = numsSize;
    int min = 9999;

    for(int i = 2; i<=2*limit; i++){
        int target_sum = i;
        int moves = 0;

        for(int j = 0; j<n/2; j++){
            int A = nums[j];
            int B = nums[n-1-j];

            if(B<A){
                int temp = A;
                A = B;
                B = temp;
            }

            if(A+1 > target_sum){
                moves+=2;
            }
            else if(A+1 <= target_sum && target_sum <= A+B-1){
                moves+=1;
            } 
            else if(A+B == target_sum){
                moves+=0;
            }
            else if(A+B+1 <= target_sum && target_sum <= B+limit){
                moves+=1;
            }
            else{
                moves+=2;
            }
        }
        if(min > moves){
            min = moves;
        }
    }
    return min;
}- O(n*limit)      */

int minMoves(int* nums, int numsSize, int limit) {
    int size = 2*limit + 2;
    int *diff = (int*)calloc(size, sizeof(int));
    int moves = numsSize;

    for(int i = 0; i<numsSize/2; i++){
        int A = nums[i];
        int B = nums[numsSize-1-i];

        if(B<A){
            int temp = A;
            A = B;
            B = temp;
        }

        //2 -> 1
        diff[A+1]-=1;

        //1 -> 0
        diff[A+B]-=1;

        //0 -> 1
        diff[A+B+1]+=1;

        //1 -> 2
        diff[B+limit+1]+=1;
    }
    int min = moves;

    for(int target = 2; target <= 2*limit; target++){
        moves += diff[target];
        if(moves < min){
            min = moves;
        }
    }
    free(diff);

    return min;  // O(N + limit)
    // diff - accumulates the changes/turning points so that we can calculate all the changes at ones (not more steps as here due to the predefined ranges [in above codes], it will be easier to calculate the diff array)
}