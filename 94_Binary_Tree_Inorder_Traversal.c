void inorder(struct TreeNode* root, int* ans, int* size) {
    if (root == NULL)
        return;

    inorder(root->left, ans, size);
    ans[(*size)++] = root->val;
    inorder(root->right, ans, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(100 * sizeof(int));
    *returnSize = 0;

    inorder(root, ans, returnSize);

    return ans;
}
