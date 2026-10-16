/*
Existing C solution:

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
*/

class Solution {
    public double findMedianSortedArrays(int[] arr1, int[] arr2) {

        //Without swapping: O(log m), where m is the length of arr1.
        //With swapping: O(log(min(m,n))), because binary search always runs on the smaller array.
        if(arr1.length > arr2.length)
            return findMedianSortedArrays(arr2, arr1);

        int m = arr1.length;
        int n = arr2.length;

        int low = 0;
        int high = arr1.length;

        while(low <= high){
            int i = low + (high - low)/2; //This is the partition for the arr1 - says the no. of elements in the left side of the arr1 [automatically determines the remaining elements are on the right side]
            int j = (m+n+1)/2 - i; //This is the partion for the arr2; Depends on the i; where the j is the no. of the elements in the right side of the arr2 [similarly says the remaining elements are on the left side]

            //The total left side elements == The total right side elements [at original partition]

            int left1 = (i == 0) ? Integer.MIN_VALUE : arr1[i-1];
            int right1 = (i == m) ? Integer.MAX_VALUE : arr1[i];

            int left2 = (j == 0) ? Integer.MIN_VALUE : arr2[j-1];
            int right2 = (j == n) ? Integer.MAX_VALUE : arr2[j];

            if(left1 <= right2 && left2 <= right1){ //The valid partition is done now;
            //Means the all the elements in the left partition <= all the elements in the right partition

                if((m+n) % 2 == 1){
                    return Math.max(left1, left2);
                }
                else{
                    return ((double)Math.max(left1, left2) + (double) Math.min(right1, right2))/2.0;
                }

            }

            if(left1 > right2)
                high = i - 1; // Making the left side of the both arr <= right side of the both arr

            else    
                low = i + 1;
        }

        return 0.0;
    }
}
