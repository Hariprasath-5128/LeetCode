/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool ismirror(struct TreeNode* root1, struct TreeNode* root2){
    if(root1  == NULL && root2 == NULL)
        return true;
    else if(root1 == NULL || root2 == NULL)
        return false;
    else if(root1->val != root2->val){
        return false;
    }
    return ismirror(root1->right, root2->left) && ismirror(root1->left, root2->right);
}
bool isSymmetric(struct TreeNode* root){
    if(root==NULL)
        return NULL;
    else
        return ismirror(root->left, root->right);
}