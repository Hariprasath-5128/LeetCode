/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {

    *returnSize = 2;
    int* ans = malloc(2 * sizeof(int));

    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }

    struct ListNode* prev = head;
    struct ListNode* ptr = head->next;


    int prevInd = -1;
    int firstInd = -1;

    int ind = 1;
    int min = 10000000;
    int max = 0;

    int criticalCount = 0;

    while(ptr->next != NULL){
        int temp = ptr->val;

        if(prev->val > temp && ptr->next->val > temp){
            if(firstInd == -1){
                firstInd = ind;
            }
            else{
                int distance = ind - prevInd;

                if(distance < min)
                    min = distance;

                max = ind - firstInd;
            }
            prevInd = ind;
            criticalCount++;
        }

        if(prev->val < temp && ptr->next->val < temp){
            if(firstInd == -1){
                firstInd = ind;
            }
            else{
                int distance = ind - prevInd;

                if(distance < min)
                    min = distance;

                max = ind - firstInd;
            }
            prevInd = ind;
            criticalCount++;
        }

        ind++;
        prev = ptr;
        ptr = ptr->next;
    }

    if(criticalCount < 2){
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    else{
        ans[0] = min;
        ans[1] = max;
        return ans;
    }

}
