/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 typedef struct {
    int depth;
    struct TreeNode* lca;
 } Info;
 
 Info dfs(struct TreeNode* root){
    if(root == NULL){
        Info base = {-1, NULL};
        return base;
    }

    Info left = dfs(root->left);
    Info right = dfs(root->right);

    Info ans;

    if(left.depth == right.depth){
        ans.depth = left.depth + 1;
        ans.lca = root;
    }
    else if(left.depth > right.depth){
        ans.depth = left.depth + 1;
        ans.lca = left.lca;
    }
    else{
        ans.depth = right.depth + 1;
        ans.lca = right.lca;
    }
    return ans;
 }

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    return dfs(root).lca;
}