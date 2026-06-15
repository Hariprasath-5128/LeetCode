/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {

    if(head == NULL)
        return NULL;

    if(head->next == NULL){
        free(head);
        return NULL;
    }

    struct ListNode* ptr = head;

    int len = 0;

    //Finding the length of list
    while(ptr != NULL){
        len++;
        ptr = ptr->next;
    }

    ptr = head;

    int mid = len / 2;

    while(mid - 1 > 0){
        mid--;
        ptr = ptr->next;
    }

    struct ListNode* toDelete = ptr->next;
    ptr->next = toDelete->next;

    free(toDelete);

    return head;
}
