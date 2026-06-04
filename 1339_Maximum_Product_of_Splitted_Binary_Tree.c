/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

long long totalSum = 0;
long long maxAnswer = 0;

int subTreeSum(struct TreeNode* root) {
    if(root == NULL)
        return 0;

    int leftSum = subTreeSum(root->left);
    int rightSum = subTreeSum(root->right);

    int total = root->val + leftSum + rightSum; // Sum of SubTree

    long long ans = (totalSum - total) * (long long)total;

    if(ans > maxAnswer)
        maxAnswer = ans;

    return total;
}

int findTotalSum(struct TreeNode* root){
    if(root == NULL)
        return 0;

    return root->val + findTotalSum(root->left) + findTotalSum(root->right);
}

int maxProduct(struct TreeNode* root) {
    //For each test case it should refresh, it should not use the previous test case result
    totalSum = 0;
    maxAnswer = 0;

    totalSum = findTotalSum(root);
    subTreeSum(root);

    return maxAnswer % 1000000007;
}
