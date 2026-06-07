/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(struct TreeNode* root, int* ans, int* size){
    if(root == NULL)
        return;

    ans[(*size)++] = root->val;

    dfs(root->left, ans, size);
    dfs(root->right, ans, size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(100 * sizeof(int));
    *returnSize = 0;

    dfs(root, ans, returnSize);

    return ans;
}