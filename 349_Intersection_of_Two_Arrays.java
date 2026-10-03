class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int ptr1 = 0;
        int ptr2 = 0;
        Set<Integer> resultList = new HashSet<>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        while(ptr1 < nums1.length && ptr2 < nums2.length){
            if(nums1[ptr1] == nums2[ptr2]){
                resultList.add(nums1[ptr1]);
                ptr1++;
                ptr2++;
            }
            else if(nums1[ptr1] > nums2[ptr2]){
                ptr2++;
            }
            else
                ptr1++;
        }

        // Convert ArrayList to a primitive int array
        int[] result = new int[resultList.size()];
        int j = 0;
        for (int i : resultList) {
            result[j] = i;
            j++;
        }
        
        return result;
    }
}