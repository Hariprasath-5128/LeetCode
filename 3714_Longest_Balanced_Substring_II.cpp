class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;

        //Case - 1 
        //Longest consecutive substring - aabbbbbbcc -> only detectable in case 1 ->answer = 7 (b)

        int run = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1])
                run++;
            else
                run = 1;
            ans = max(ans, run);
        }

        //Case - 2
        //If a substring contains exactly two distinct characters, and both appear the same no. of times - so we compute for pair(a,b), pair(a,c), pair(c,b)

        //ababc -> 4 (abab)

        //When a character other than pair occurs, reset the diff and first wrt the current index as the starting position

        auto solve2 = [&](char x, char y){
            unordered_map<int, int> first;

            int cx = 0, cy = 0;
            int diff = 0;
            int best = 0;

            first[0] = -1;

            for(int i = 0; i < n; i++){

                if(s[i] != x && s[i] != y){
                    first.clear();
                    first[0] = i;

                    cx = cy = 0;
                    diff = 0;
                    continue;
                }

                if(s[i] == x){
                    cx++;
                    diff++;
                }
                else{
                    cy++;
                    diff--;
                }

                if (!first.count(diff))
                    first[diff] = i;
                else
                    best = max(best, i - first[diff]);
            }

            return best;
        };

        ans = max(ans, solve2('a', 'b'));
        ans = max(ans, solve2('a', 'c'));
        ans = max(ans, solve2('b', 'c'));

        //Case - 3
        // If a substring contains exactly three distinct characters, all three must appear the same number of times.
        // We track two differences: (count(a)-count(b), count(b)-count(c)).
        // Whenever the same pair of differences repeats, the substring between them is balanced.

        map<pair<int, int>, int> first;

        int ca = 0, cb = 0, cc = 0;
        first[{0, 0}] = -1;

        for(int i = 0; i < n; i++){

            if(s[i] == 'a')
                ca++;
            else if(s[i] == 'b')
                cb++;
            else
                cc++;

            pair<int, int> state = {
                ca - cb,
                cb - cc
            };

            if(!first.count(state))
                first[state] = i;
            else
                ans = max(ans, i - first[state]);
        }

        return ans;
    }
};
