class Solution {
    public boolean validPalindrome(String s) {
        char[] arr = s.toCharArray();
        int left = 0;
        int right = arr.length - 1;

        int mismatch = 0;
        boolean ans1 = true;
        boolean ans2 = true;

        while(left < right){
            if(arr[left] == arr[right]){
                left++;
                right--;
            }
            else if(arr[left] != arr[right] && arr[left + 1] == arr[right]){
                left++;
                mismatch++;
            }
            else if(arr[left] != arr[right] && arr[left] == arr[right - 1]){
                right--;
                mismatch++;
            }
            else{
                mismatch++;
            }

            if(mismatch > 1){
                ans1 = false;
                break;
            }

        }

        left = 0;
        right = arr.length - 1;
        mismatch = 0;
        while(left < right){
            if(arr[left] == arr[right]){
                left++;
                right--;
            }
            else if(arr[left] != arr[right] && arr[left] == arr[right - 1]){
                right--;
                mismatch++;
            }
            else if(arr[left] != arr[right] && arr[left + 1] == arr[right]){
                left++;
                mismatch++;
            }
            else{
                mismatch++;
            }

            if(mismatch > 1){
                ans2 = false;
                break;
            }
        }

        return ans1 || ans2;
    }
}

/*
Similar to this:

    if (chars[l] != chars[r]) {
    return isPalindrome(chars, l + 1, r) ||
           isPalindrome(chars, l, r - 1);
    }

*/
