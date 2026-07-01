/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *arr[10000];
int idx;

// Given a BST, inorder traversal stores the nodes in sorted order.
void inorder(struct TreeNode *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    arr[idx++] = root;
    inorder(root->right);
}

// Build a balanced BST from the sorted array.
struct TreeNode* build(int left, int right) {
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;
    struct TreeNode *root = arr[mid];

    root->left = build(left, mid - 1);
    root->right = build(mid + 1, right);

    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    idx = 0;

    // Store nodes in sorted order.
    inorder(root);

    // Construct a balanced BST.
    return build(0, idx - 1);
}
