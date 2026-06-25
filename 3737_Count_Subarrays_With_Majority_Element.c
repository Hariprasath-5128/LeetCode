/*

Algorithm: Count Subarrays With Majority Element
Idea:
A subarray is valid if the target appears more times than all the other elements combined.

Let, 
Target count = T
Other elements count = O

Condition: T > O

Instead of counting target occurrences directly, transform the array.

If nums[i] == target
    value = +1
Else
    value = -1

Now, Subarray Sum = Target Count - Other Count

Therefore, Target is majority ⇔ Subarray Sum > 0

So the problem becomes:
Count the number of subarrays having positive sum.

Step 1 : Build Prefix Sum
        Create prefix array.
        prefix[0] = 0

        for i = 0 to n-1

            if nums[i] == target
                prefix[i+1] = prefix[i] + 1
            else
                prefix[i+1] = prefix[i] - 1


            Now, Subarray Sum (l...r) = prefix[r+1] - prefix[l]

            We need, prefix[r+1] - prefix[l] > 0 (so that it is a valid subarray) ⇔ prefix[l] < prefix[r+1]
            So for every current prefix sum,

            we only need to know: How many previous prefix sums are smaller than it?


Step 2 : Coordinate Compression

        Prefix sums may be -100000 ... +100000
        Fenwick Tree cannot use negative indices.

        So,
            Copy all prefix sums.
            Sort them.
            Remove duplicates.
            Assign every unique prefix sum an index.

            Example: Prefix [0 -1 0 1 0] → Sorted [-1 0 1] →

            Mapping:    
                -1 -> 1
                 0 -> 2
                 1 -> 3


Step 3 : Initialize Fenwick Tree

            Fenwick Tree stores frequencies.

            Initially, All frequencies = 0
            Answer = 0


Step 4 : Process Every Prefix Sum
            For every prefix sum
            Find compressed index.
            idx = lowerBound(values, prefix) + 1

            Query:
                query(idx-1)

            This returns
                Number of previous prefix sums strictly smaller than current prefix.

            Add it to answer: ans += query(idx-1)
            Now insert current prefix into Fenwick Tree : update(idx)

        Repeat for every prefix.



Fenwick Tree Operations
    i) Update
        update(index)

        while(index <= size)

            bit[index]++
            index += index & (-index)

        Meaning:
        Increase the frequency of the current prefix sum.
        Move to every larger BIT node whose range also contains this index.

    ii) Query
        query(index)

        sum = 0
        while(index > 0)
            sum += bit[index]
            index -= index & (-index)

        return sum

        Meaning
        Return the total frequency of all compressed indices from 1 ... index

        This equals:
        Number of previous prefix sums
        strictly smaller than current prefix.

*/


int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

//binary search
int lowerBound(int *arr, int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

//Using Fenwick Tree, used for sum of array in range [l, r] in log n times

/*

Index	Binary	i & -i(end)	 Start = i-(i&-i)+1	  Range
1	     0001	   1	            1	            1
2	     0010	   2	            1	            1–2
3	     0011	   1	            3	            3
4	     0100	   4	            1               1–4
5	     0101	   1	            5               5
6	     0110	   2	            5	            5–6
7	     0111	   1	            7	            7
8	     1000	   8	            1	            1–8

*/

void update(int *bit, int size, int index){
    while(index <= size){
        bit[index]++;
        index += index & (-index);//fenwich traversing (bit manipulation)
    }
}

long long query(int *bit, int index) {
    long long sum = 0;

    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }

    return sum;
}

int countMajoritySubarrays(int* nums, int numsSize, int target) {
    //Step 1: Build prefix sum (+1 for target, -1 otherwise)
    int *prefix = (int *)malloc((numsSize+1)*sizeof(int));
    prefix[0] = 0;

    for(int i = 0; i<numsSize; i++){
        if(nums[i] == target)
            prefix[i+1] = prefix[i] + 1;
        else
            prefix[i+1] = prefix[i] - 1;
    }

    //Step 2: Coordinate Compression
    int *values = (int *)malloc((numsSize + 1)* sizeof(int));

    for(int i = 0; i<=numsSize; i++)
        values[i] = prefix[i];

    qsort(values, numsSize+1, sizeof(int), cmp);

    int m = 0; 
    for(int i = 0; i<=numsSize; i++){
        if(i==0 || values[i] != values[i-1])
            values[m++] = values[i];
    }

    //Step 3: Fenwick Tree
    int *bit = (int *)calloc(m+1, sizeof(int));
    int ans = 0;

    for(int i = 0; i<= numsSize; i++){
        int idx = lowerBound(values, m, prefix[i])+1;

        //Count previous prefix sums smaller than current
        ans+= query(bit, idx-1);

        //Insert current prefix sum
        update(bit, m, idx);
    }

    free(prefix);
    free(values);
    free(bit);

    return ans;
}