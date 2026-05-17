bool canReach(int* nums, int numsSize, int start) {

    int visited[numsSize];

    for(int i = 0; i < numsSize; i++){
        visited[i] = 0;
    }

    int stack[numsSize];
    int top = -1;

    stack[++top] = start;

    while(top >= 0){

        int pos = stack[top--];

        if(nums[pos] == 0){
            return true;
        }

        if(visited[pos] == 1){
            continue;
        }

        visited[pos] = 1;

        int left = pos - nums[pos];
        int right = pos + nums[pos];

        // left move
        if(left >= 0 && left < numsSize && visited[left] == 0){
            stack[++top] = left;
        }

        // right move
        if(right >= 0 && right < numsSize && visited[right] == 0){
            stack[++top] = right;
        }
    }

    return false;
}
