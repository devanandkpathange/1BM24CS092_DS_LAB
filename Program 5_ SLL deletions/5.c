/**
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

Node *create(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void insert_begin(int data)
{
    Node *newnode;
    newnode = create(data);
    if (head == NULL)
        head = newnode;
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void delete_begin()
{
    Node *temp;
    if (head == NULL)
    {
        printf("Cannot be deleted\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void delete_end()
{
    Node *temp1, *temp2;
    if (head == NULL)
    {
        printf("Cannot be deleted\n");
        return;
    }
    temp1 = head;
    temp2 = NULL;
    while (temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp2 == NULL)
        head = NULL;
    else
        temp2->next = NULL;
    free(temp1);
}

void delete_pos(int p)
{
    int c = 1;
    Node *temp1, *temp2;
    if (head == NULL)
    {
        printf("Cannot be deleted\n");
        return;
    }
    if (p == 1)
    {
        delete_begin();
        return;
    }
    temp1 = head;
    temp2 = NULL;
    while (c < p && temp1 != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        c++;
    }
    if (temp1 == NULL)
    {
        printf("Out of range\n");
        return;
    }
    temp2->next = temp1->next;
    free(temp1);
}

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch, data, pos;

    printf("MENU\n1.Insert begin\n2.Delete begin\n3.Delete end\n4.Delete position\n5.Display\n6.Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            insert_begin(data);
            break;
        case 2:
            delete_begin();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid input\n");
        }
    }
}


**/
