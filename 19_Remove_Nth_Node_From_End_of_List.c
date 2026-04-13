/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* f = head;
    struct ListNode* s = head;
    struct ListNode* prev = head;
    for(int i = 0; i<n; i++){
        f = f->next;
    }
    if (f == NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    while(f!=NULL){
        prev = s;
        f = f->next;
        s = s->next;
    }
    struct ListNode* temp = prev->next;
    
    prev->next = s->next;
    free(temp);
    return head;
}