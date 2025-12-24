struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *temp1 = head, *temp2 = NULL;
    
    while (temp1 != NULL) {
        if (temp1->val == val) {
            if (temp2 == NULL) {
                // deleting head node
                head = temp1->next;
                temp1 = head;
            } else {
                // deleting non-head node
                temp2->next = temp1->next;
                temp1 = temp1->next;
            }
        } else {
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }
    
    return head;
}
