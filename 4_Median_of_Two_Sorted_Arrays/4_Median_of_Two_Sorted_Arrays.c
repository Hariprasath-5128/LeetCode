double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums1Size, n = nums2Size;
    int result[m+n];
    int k = 0, i = 0, j = 0;

    while(i < m && j < n){
        if(nums1[i]<nums2[j]){
            result[k++] = nums1[i];
            i++;
        }
        else{
            result[k++] = nums2[j];
            j++;
        }
    }
    while(i<m){
        result[k++] = nums1[i];
        i++;
    }
    while(j<n){
        result[k++] = nums2[j];
        j++;
    }
    int mid = (m+n)/2;
    if((m+n)%2==0){
        return (result[mid]+result[mid-1])/2.0;
    }
    else{
        return result[mid];
    }
}