/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode *insert(struct ListNode *t,int data)
 {
    struct ListNode *nn=(struct ListNode*)malloc(sizeof(struct ListNode));
    nn->val=data;
    nn->next=NULL;
    struct ListNode *a=t;
    if(a==NULL)
    {
        return nn;
    }
    while(a->next!=NULL)
    {
        a=a->next;
    }
    a->next=nn;
    return t;
 }
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *t1=list1,*t2=list2,*dummy=NULL;
    if(list1==NULL)
    return list2;
    if(list2==NULL)
    return list1;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->val==t2->val)
        {
            dummy=insert(dummy,t1->val);
            dummy=insert(dummy,t2->val);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->val<t2->val)
        {
            dummy=insert(dummy,t1->val);
            t1=t1->next;

        }
        else
        {
            dummy=insert(dummy,t2->val);
        t2=t2->next;
        }
        
    }
    if(t1==NULL && t2!=NULL)
    {
        while(t2!=NULL)
        {
            dummy=insert(dummy,t2->val);
            t2=t2->next;
        }
    }
    else if(t2==NULL && t1!=NULL)
    {
        while(t1!=NULL)
        {
            dummy=insert(dummy,t1->val);
            t1=t1->next;
        }
    }
    return dummy;
    
}