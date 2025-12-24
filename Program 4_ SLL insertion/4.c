/**#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

struct node *create(int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void insert_beg(int data)
{
    struct node *newnode;
    newnode = create(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void insert_end(int data)
{
    struct node *newnode, *temp;
    newnode = create(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insert_position(int data, int pos)
{
    struct node *newnode, *temp, *temp2;
    int i = 1;
    newnode = create(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else if (pos == 1)
    {
        insert_beg(data);
    }
    else
    {
        temp = head;
        while (i < pos - 1 && temp != NULL)
        {
            temp2 = temp;
            temp = temp->next;
            i++;
        }
        if (temp == NULL && i < pos)
        {
            printf("Insertion is not possible\n");
            free(newnode);
        }
        else
        {
            newnode->next = temp2->next;
            temp2->next = newnode;
        }
    }
}

void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value, pos;
    printf("1.Insert begin\n2.Insert end\n3.Insert position\n4.Display\n");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d", &value);
            insert_beg(value);
            break;
        case 2:
            scanf("%d", &value);
            insert_end(value);
            break;
        case 3:
            scanf("%d%d", &value, &pos);
            insert_position(value, pos);
            break;
        case 4:
            display();
            break;
        default:
            return 0;
        }
    }
}
**/
