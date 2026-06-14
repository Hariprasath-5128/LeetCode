/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    int maxAns = INT_MIN;

    struct ListNode* midPointer = head;
    struct ListNode* ptr = head;

    int len = 0;
    
    //Finding the length of list
    while(ptr != NULL){
        len++;
        ptr = ptr->next;
    }
    ptr = head;

    int mid = (int)len/2 - 1; //always len is even; given in question
    //For pointing to the mid; here midPointer = just before element of the second half
    while(mid>0){
        midPointer = midPointer->next;
        mid--;
    }

    //Reversing the second half of the list
    struct ListNode* prev = NULL;
    struct ListNode* curr = midPointer->next;
    struct ListNode* nextp = NULL;
    midPointer->next = NULL;
    
    while(curr != NULL){
        nextp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextp;
    }
    midPointer->next = prev;

    //Finding the twin sum
    midPointer = midPointer->next;
    while(midPointer != NULL){
        int temp = ptr->val + midPointer->val;
        if(maxAns < temp)
            maxAns = temp;
        
        ptr = ptr->next;
        midPointer = midPointer->next;
    }
    return maxAns;
}
