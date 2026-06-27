int minimumDistance(int* nums, int numsSize) {
    int ans = INT_MAX;
    int n = numsSize;

    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){

            if(nums[i] != nums[j])
                continue;

            for(int k = j+1; k < n; k++){

                if(nums[i] == nums[j] && nums[i] == nums[k]){
                    int dist = 2 * (k-i);

                    if(dist < ans)
                        ans = dist;
                }
            }
        }
    }
    return ans == INT_MAX ? -1:ans;
}
