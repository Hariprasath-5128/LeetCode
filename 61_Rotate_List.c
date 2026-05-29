/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {

    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode* root = head;
    struct ListNode* root1 = head;
    int len = 0;

    while(root1 != NULL){
        len++;
        root1 = root1->next;
    }

    k = k % len;

    if(k == 0)
        return head;

    while(k > 0) {

        struct ListNode* curr = root;

        while(curr->next->next != NULL) {
            curr = curr->next;
        }

        struct ListNode* last = curr->next;

        curr->next = NULL;
        last->next = root;

        root = last;
        k--;
    }

    return root;
}
