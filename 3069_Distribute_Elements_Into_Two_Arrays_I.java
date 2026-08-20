class Solution {
    public int[] resultArray(int[] nums) {
        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();

        arr1.add(nums[0]);
        arr2.add(nums[1]);

        int arr1Last = nums[0];
        int arr2Last = nums[1];

        for(int i = 2; i<nums.length; i++){
            if(arr1Last > arr2Last){
                arr1Last = nums[i];
                arr1.add(arr1Last);
            }

            else{
                arr2Last = nums[i];
                arr2.add(arr2Last);
            }
        }

        int[] result = new int[arr1.size() + arr2.size()];
        int i = 0;

        for(i = 0; i < arr1.size(); i++){
            result[i] = arr1.get(i);
        }

        for(int j = i;j < arr2.size() + i; j++){
            result[j] = arr2.get(j-i);
        }

        return result;
    }
}