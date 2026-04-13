/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode* s = head;
    int c = 0;
    while(s!=NULL){
        c++;
        s = s->next;
    }
    s = head;
    if(c==1){
        struct ListNode* temp1 = head;
        head = head->next;
        free(temp1);
        return head;
    }
    int mid = (int)(c/2);

    while(mid-1!=0){
        s = s->next;
        mid--;
    }
    struct ListNode* temp = s->next;
    
    s->next = s->next->next;
    free(temp);
    return head;
}