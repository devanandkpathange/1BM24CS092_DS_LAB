/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *temp1=head;
    struct ListNode *s=head,*f=head;
    while(1)
    {
        if(f==NULL)
        {
            return NULL;
        }
        else
        {
            if(f->next==NULL)
            return NULL;
            else
            {
                if(f->next->next==NULL)
                return NULL;
                else{
                    f=f->next->next;
            s=s->next;
            if(f==s)
        {
            break;;
        }
                }
                
            }
            
        }
        
    }
    s=head;
    while(s!=f)
    {
        s=s->next;
        f=f->next;
    }
    return s;
}