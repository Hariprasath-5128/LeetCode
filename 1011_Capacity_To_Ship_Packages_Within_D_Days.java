class Solution {\
   public int shipWithinDays(int[] weights, int days) {\
       int sum = 0;\
       int max = 0;\
       for(int i: weights){\
           max = Math.max(max, i);\
           sum += i;\
       }\
\
       int right = sum; // maximum possible capacity - because then we can carry all weights in one day\
       int left = max; // minimum possible capacity - because ship must atleast carry this weight \n\
       int ans = 0;\
       while(left < right){\
           int mid = left + (right - left)/2;\
\
           int capacity = mid;\
           int day_used = 0;\
           int curr_weight = 0;\
\
           for(int w: weights){\
               if(curr_weight + w > capacity){\
                   day_used += 1;\
                   curr_weight = w;\
               }\
               else{\
                   curr_weight += w;\
               }\
           }\
           day_used++; //Counting the last day\
\
           if(day_used > days){ //If we are getting the day_used as higher; then we are having low capacity\
               left = mid + 1;\
           }\
           else\
               right = mid;\
       }\
\
       return left;\
   }\
}
