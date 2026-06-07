/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int value){
    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val = value;
    root->left = NULL;
    root->right = NULL;

    return root;
}

struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {

    struct TreeNode* node[100001] = {NULL};
    bool isChild[100001] = {false};

    for(int i = 0; i<descriptionsSize; i++){

        int parent = descriptions[i][0];
        int child = descriptions[i][1];
        int isLeft = descriptions[i][2];

        if(node[parent] == NULL)
            node[parent] = createNode(parent);

        if(node[child] == NULL)
            node[child] = createNode(child);

        if(isLeft)
            node[parent]->left = node[child];
        else
            node[parent]->right = node[child];
        
        isChild[child] = true;
    }

    for(int i = 0; i<100001; i++){
        if(!isChild[i] && node[i])
            return node[i];
    }
    return NULL;
}