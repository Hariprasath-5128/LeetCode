/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int helper(struct TreeNode* root, int curr){
    if(root == NULL)
        return 0;

    curr = curr << 1 | root->val; //appending the new bit at the last

    if(root->left == NULL && root->right == NULL)
        return curr;

    return helper(root->left, curr) + helper(root->right, curr);
}

int sumRootToLeaf(struct TreeNode* root) {

    return helper(root, 0);
}
