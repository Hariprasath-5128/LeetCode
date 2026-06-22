struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right)
        return head;

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prev = &dummy;

    // Move prev to node before left
    for (int i = 1; i < left; i++)
        prev = prev->next;

    struct ListNode *start = prev->next; // left node
    struct ListNode *curr = start;
    struct ListNode *next, *revPrev = NULL;

    // Reverse right-left+1 nodes normally
    for (int i = 0; i <= right - left; i++) {
        next = curr->next;
        curr->next = revPrev;
        revPrev = curr;
        curr = next;
    }

    // Connect back
    prev->next = revPrev;
    start->next = curr;

    return dummy.next;
}
