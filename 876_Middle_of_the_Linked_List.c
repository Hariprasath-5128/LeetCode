/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        
        else
            break;

        slow = slow->next;
    }

    return slow;
}
