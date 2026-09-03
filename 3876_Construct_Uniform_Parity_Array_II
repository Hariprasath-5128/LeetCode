/*

Find smallest odd
       ↓
Check every even
       ↓
Is even < smallest odd?
       ↓
   YES → false
   NO  → continue
       ↓
All passed → true

*/

bool uniformArray(int* nums1, int nums1Size) {
    bool isAllEven = true;

    for(int i = 0; i < nums1Size; i++){
        if(nums1[i] % 2 != 0){
            isAllEven = false;
            break;
        }
    }

    bool isAllOdd = true;

    for(int i = 0; i < nums1Size; i++){
        if(nums1[i] % 2 == 0){
            isAllOdd = false;
            break;
        }
    }

    if(isAllEven || isAllOdd)
        return true;

    bool ans1 = true;
    int minOdd = 10000;
    int minEven = 10000;

    for(int i = 0; i < nums1Size; i++){
        if(nums1[i] % 2 == 1 && minOdd > nums1[i])
            minOdd = nums1[i];

        if(nums1[i] % 2 == 0 && minEven > nums1[i])
            minEven = nums1[i];
    }

    for(int i = 0; i < nums1Size; i++){
        if(nums1[i] % 2 == 0){
            int sub = nums1[i] - minOdd;

            if(sub < 1)
                ans1 = false;
        }
    }

    return ans1;
}