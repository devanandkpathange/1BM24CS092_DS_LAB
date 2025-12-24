/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *s=head,*f=head;
    while(1)
    {
        if(f==NULL)
        {
            return 0;
        }
        else
        {
            if(f->next==NULL)
            return 0;
            else
            {
                if(f->next->next==NULL)
                return 0;
                else{
                    f=f->next->next;
            s=s->next;
            if(f==s)
        {
            return 1;
        }
                }
                
            }
            
        }
        
    }
    return 0;
}