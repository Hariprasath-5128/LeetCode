/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <limits.h>
#include <stdbool.h>

bool validate(struct TreeNode* root, long min, long max){
    // Empty tree is valid
    if(root == NULL){
        return true;
    }

    // Current node must be within range
    if(root->val <= min || root->val >= max){
        return false;
    }

    // Check left and right subtree
    return validate(root->left, min, root->val) &&
           validate(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    // Narrow down the range at each part of the subtree
    return validate(root, LONG_MIN, LONG_MAX);
}
