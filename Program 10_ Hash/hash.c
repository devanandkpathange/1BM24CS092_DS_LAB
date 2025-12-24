#include<stdio.h>
#include<stdlib.h>
int key[20],m,n,*ht,count=0,index;
void insert(int key)
{
    index=key%m;
    while(ht[index]!=-1)
    {
        index=(index+1)%m;
    }
    ht[index]=key;
    count++;
}
void display()
{
    if(count==0)
    {
        printf("Hash is empty");
        return;
    }
    printf("\nHash Table are: \n");
    for(int i=0;i<m;i++)
    {
        printf("\nT[%d]->%d",i,ht[i]);
    }
}
void main()
{
    int i;
    printf("Enter total number of Employee records : ");
    scanf("%d",&n);
    printf("Enter 2 digit memory location : ");
    scanf("%d",&m);
    ht=(int*)malloc(m*sizeof(int));
    for(i=0;i<m;i++)
    {
        ht[i]=-1;
    }
    printf("Enter 4 digit values : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&key[i]);
    }
    for(i=0;i<n;i++)
    {
        if(count==m)
        {
            printf("Hash is full:");
            break;
        }
        insert(key[i]);
    }
    display();
}
