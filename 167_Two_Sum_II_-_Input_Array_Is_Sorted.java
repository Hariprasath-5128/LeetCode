class Solution {
    static int binarySearch(int[] arr, int target){
        int left = 0;
        int right = arr.length - 1;

        while(right >= left){
            int mid = left + (right - left)/2;

            if(arr[mid] == target)
                return mid;

            else if(target < arr[mid]){
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return -1;
    }

    public int[] twoSum(int[] numbers, int target) {
        int ind1 = -1;
        int ind2 = -1;

        for(int i = 0; i < numbers.length; i++){
            int diff = target - numbers[i];
            ind2 = binarySearch(numbers, diff);

            if(ind2 != -1 && ind2 != i){ 
                ind1 = i;
                break;
            }
        }
        if(ind1 > ind2){
            int temp = ind1;
            ind1 = ind2;
            ind2 = temp;
        }
        return new int[] {ind1 + 1, ind2 + 1};
    }
}