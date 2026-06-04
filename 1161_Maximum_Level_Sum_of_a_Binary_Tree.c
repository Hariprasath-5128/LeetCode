/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxLevelSum(struct TreeNode* root) {
    struct TreeNode* queue[10001];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int currentLevel = 1; // Start at level 1
    int maxSum = INT_MIN; // Use INT_MIN to handle all-negative sums
    int bestLevel = 1;

    int levelSize = 0;

    while(rear > front){
        levelSize = rear - front;
        int sum = 0;

        for(int i = 0; i<levelSize; i++){
            struct TreeNode* curr = queue[front++];
            sum+=curr->val;

            if(curr->left)
                queue[rear++] = curr->left;
            if(curr->right)
                queue[rear++] = curr->right;

        } //SINGLE LEVEL calculation completed
        if(sum > maxSum){
            maxSum = sum;
            bestLevel = currentLevel;
        }
        currentLevel++;
    }
    return bestLevel;
}
