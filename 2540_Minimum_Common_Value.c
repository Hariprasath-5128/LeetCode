int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0;
    int j = 0;

    while(i < nums1Size && j < nums2Size){

        // If both elements are equal, return the common element
        if(nums1[i] == nums2[j]){
            return nums1[i];
        }

        // Move pointer of smaller element
        if(nums1[i] > nums2[j]){
            j++;
        }
        else{
            i++;
        }
    }

    // No common element found
    return -1;
}
