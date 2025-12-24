/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    int c=0;
    struct ListNode *temp1 = list1,*temp2=list2,*temp3,*temp4;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    while(temp1->next!=NULL)
    {
        if(c<a)
        {
            temp3=temp1;
        }
        if(c==b)
        {
            temp4=temp1;
        }
        temp1=temp1->next;
        c++;
    }
    temp3->next=list2;
    temp2->next=temp4->next;
    return list1;
}
      
