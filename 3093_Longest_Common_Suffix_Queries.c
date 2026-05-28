/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode{
    struct TrieNode* child[26];

    int bestIndex;
    int bestLength;
} TrieNode;

TrieNode* createNode(){

    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    for(int i = 0; i < 26; i++){
        node->child[i] = NULL;
    }

    node->bestIndex = INT_MAX;
    node->bestLength = INT_MAX;

    return node;
}

void updateNode(TrieNode* node, int len, int idx){

    if(len < node->bestLength ||
      (len == node->bestLength && idx < node->bestIndex)){

        node->bestLength = len;
        node->bestIndex = idx;
    }
}

void insert(TrieNode* root, char* word, int idx){

    int len = strlen(word);

    TrieNode* curr = root;

    // Update root
    updateNode(curr, len, idx);

    // Insert reversed string
    for(int i = len - 1; i >= 0; i--){

        int c = word[i] - 'a';

        if(curr->child[c] == NULL){
            curr->child[c] = createNode();
        }

        curr = curr->child[c];

        updateNode(curr, len, idx);
    }
}

int search(TrieNode* root, char* word){

    int len = strlen(word);

    TrieNode* curr = root;

    // Traverse reversed query
    for(int i = len - 1; i >= 0; i--){

        int c = word[i] - 'a';

        if(curr->child[c] == NULL){
            break;
        }

        curr = curr->child[c];
    }

    return curr->bestIndex;
}

int* stringIndices(char** wordsContainer, int wordsContainerSize,
                   char** wordsQuery, int wordsQuerySize,
                   int* returnSize) {

    TrieNode* root = createNode();

    // Build Trie
    for(int i = 0; i < wordsContainerSize; i++){
        insert(root, wordsContainer[i], i);
    }

    int* ans = (int*)malloc(sizeof(int) * wordsQuerySize);

    // Process queries
    for(int i = 0; i < wordsQuerySize; i++){
        ans[i] = search(root, wordsQuery[i]);
    }

    *returnSize = wordsQuerySize;

    return ans;
} -  This code failed only due to the SC = O(26* All Char) - Memory limit Exceeded. So using the sibling (next possible character) and edge concept we can solve it using O(All Char)*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode TrieNode;

typedef struct Edge{
    char ch;
    TrieNode* next;
    struct Edge* sibling;
} Edge;

struct TrieNode{
    Edge* head;

    int bestIndex;
    int bestLength;
};

TrieNode* createNode(){

    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    node->head = NULL;
    node->bestIndex = INT_MAX;
    node->bestLength = INT_MAX;

    return node;
}

void updateNode(TrieNode* node, int len, int idx){

    if(len < node->bestLength ||
      (len == node->bestLength && idx < node->bestIndex)){

        node->bestLength = len;
        node->bestIndex = idx;
    }
}

TrieNode* getChild(TrieNode* node, char ch){

    Edge* curr = node->head;

    while(curr){
        if(curr->ch == ch){
            return curr->next;
        }
        curr = curr->sibling; //check for nearer character with same level
    }

    return NULL;
}

TrieNode* createChild(TrieNode* node, char ch){

    TrieNode* childNode = createNode();

    Edge* edge = (Edge*)malloc(sizeof(Edge));

    edge->ch = ch;
    edge->next = childNode;

    edge->sibling = node->head;
    node->head = edge;

    return childNode;
}

void insert(TrieNode* root, char* word, int idx){

    int len = strlen(word);

    TrieNode* curr = root;

    updateNode(curr, len, idx);

    for(int i = len - 1; i >= 0; i--){

        char ch = word[i];

        TrieNode* child = getChild(curr, ch);

        if(child == NULL){
            child = createChild(curr, ch);
        }

        curr = child;

        updateNode(curr, len, idx);
    }
}

int search(TrieNode* root, char* word){

    int len = strlen(word);

    TrieNode* curr = root;

    for(int i = len - 1; i >= 0; i--){

        TrieNode* child = getChild(curr, word[i]);

        if(child == NULL){
            break;
        }

        curr = child;
    }

    return curr->bestIndex;
}

int* stringIndices(char** wordsContainer, int wordsContainerSize,
                   char** wordsQuery, int wordsQuerySize,
                   int* returnSize) {

    TrieNode* root = createNode();

    for(int i = 0; i < wordsContainerSize; i++){
        insert(root, wordsContainer[i], i);
    }

    int* ans = (int*)malloc(sizeof(int) * wordsQuerySize);

    for(int i = 0; i < wordsQuerySize; i++){
        ans[i] = search(root, wordsQuery[i]);
    }

    *returnSize = wordsQuerySize;

    return ans;
}