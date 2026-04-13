/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* result = head;
    struct ListNode* prev = NULL;
    int carry = 0;

    while(l1!=NULL && l2 !=NULL){
        int temp = l1->val + l2->val+carry;
        carry = temp / 10;

        result->val = temp % 10;
        prev = result;

        result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        result = result->next;
        
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1!=NULL){
        int temp = l1->val + carry;
        result->val = temp%10;
        carry = temp/10;

        prev = result;

        result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        result = result->next;
        l1 = l1->next;
    }
    while(l2!=NULL){
        int temp = l2->val + carry;
        result->val = temp%10;
        carry = temp/10;

        prev = result;

        result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        result = result->next;
        l2 = l2->next;
    }
    if(carry==1){
        result->val = 1; 
        result->next = NULL;
    }
    else if(carry == 0){
        prev->next = NULL; 
    }

    return head;
}