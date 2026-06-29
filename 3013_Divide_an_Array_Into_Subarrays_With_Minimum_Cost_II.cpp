/*

Algorithm:
1. The firest Subarray always starts at index 0.
    So nums[0] is always part of the answer.

2. Choose the starting index of the second subarray (s1).
    Try every possible s1.

3. For each s1, consider the window: [s1, s1 + dist]
    This window contains all possible starting positions of the remaining subarrays.

4. From this window, choose the smallest k-1 values (including nums[s1]).
    These values become the costs of the 2nd, 3rd, ..., kth subarrays.

5. Maintain these smallest k-1 values efficiently using:
    low → stores the smallest k-1 values.
    high → stores the remaining values.

6. Slide the window one step at a time.
    Remove the leftmost element.
    Add the new rightmost element.
    Rebalance low and high.

7. Keep track of: answer = min(answer, sum(low))

8. Final answer: nums[0] + answer

*/

/*

Algorithm
│
├── Low (stores smallest k values)
│      │
│      └── implemented using a Treap (in C)
│          or multiset (in C++)  -- stores in sorted format, and (insert, delete - O(log n))
│
└── High (stores remaining values)
       │
       └── implemented using a Treap (in C)
           or multiset (in C++)

*/

class Solution {
public:

    struct SmartWindow{
        int K;
        multiset<int> low, high;
        long long sumLow = 0;

        SmartWindow(int k){
            K = k;
        }

        int windowSize(){
            return low.size() + high.size();
        }

        void rebalance(){
            int need = min(K, windowSize());

            while(low.size() > need){
                auto it = prev(low.end());
                int x = *it;

                low.erase(it);
                sumLow -= x;

                high.insert(x);
            }

            while(low.size() < need && !high.empty()){
                auto it = high.begin();
                int x = *it;

                high.erase(it);

                low.insert(x);
                sumLow += x;
            }
        }

        void add(int x){
            if(low.empty() || x <= *prev(low.end())){
                low.insert(x);
                sumLow += x;
            } else {
                high.insert(x);
            }
            rebalance();
        }

        void remove(int x){
            auto it = low.find(x);

            if(it != low.end()){
                low.erase(it);
                sumLow -= x;
            } else {
                high.erase(high.find(x));
            }

            rebalance();
        }

        long long query() {
            return sumLow;
        }
    };

    long long minimumCost(vector<int>& nums, int k, int dist) {

        int n = nums.size();

        k--;

        SmartWindow window(k);

        for(int i = 1; i <= dist + 1; i++){
            window.add(nums[i]);
        }

        long long ans = window.query();

        for(int i = 2; i + dist < n; i++){
            window.remove(nums[i - 1]);
            window.add(nums[i + dist]);

            ans = min(ans, window.query());
        }

        return ans + nums[0];
    }
};
