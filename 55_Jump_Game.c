/* DFS Approach

bool canJump(int* nums, int numsSize) {

    int visited[numsSize];
    for (int i = 0; i < numsSize; i++) {
        visited[i] = 0;
    }

    int stack[numsSize];
    int top = -1;

    stack[++top] = 0;

    while (top >= 0) {

        int pos = stack[top--];

        if(pos >= numsSize - 1){
            return true;
        }

        if(visited[pos] == 1){
            continue;
        }

        visited[pos] = 1;

        for(int jump = 1; jump <= nums[pos]; jump++){

            int tryRight = pos + jump;

            if (tryRight >= 0 && tryRight < numsSize && visited[tryRight] == 0) {
                stack[++top] = tryRight;
            }
        }
    }

    return false;
}
*/


// Greedy Approach
bool canJump(int* nums, int numsSize) {

    int maxReach = 0;

    for(int i = 0; i < numsSize; i++){

        // cannot even reach this index
        if(i > maxReach){
            return false;
        }

        // update farthest reachable index
        if(i + nums[i] > maxReach){
            maxReach = i + nums[i];
        }

        // already can reach end
        if(maxReach >= numsSize - 1){
            return true;
        }
    }

    return true;
}
