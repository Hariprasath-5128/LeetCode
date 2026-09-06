class Solution {
public int singleNonDuplicate(int[] nums) {
int left = 0;
int right = nums.length - 1;

    while(left < right){ 
        int mid = left + (right - left)/2; 

        if(mid % 2 == 0 && nums[mid] != nums[mid+1]){ 
            right = mid; 
            continue; 
        } 

        else if(mid % 2 == 0 && nums[mid] == nums[mid+1]){ 
            left = mid + 2; 
            continue; 
        } 

        if(mid % 2 == 1 && nums[mid] == nums[mid-1]){ 
            left = mid + 1; 
            continue; 
        } 

        else if(mid % 2 == 1 && nums[mid] != nums[mid-1]){ 
            right = mid; 
            continue; 
        } 

    } 
    return nums[left]; 
} 
}
