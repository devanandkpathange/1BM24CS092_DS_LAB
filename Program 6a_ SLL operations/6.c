/**
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
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

void insert_beg(int data)
{
    Node *newnode = create(data);
    if (head == NULL)
        head = newnode;
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

Node *reverse(Node *head1)
{
    Node *prev = NULL, *curr = head1, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *sort(Node *head1)
{
    Node *ptr, *ptr2;
    int temp;
    if (head1 == NULL)
        return head1;

    do
    {
        int swap = 0;
        ptr = head1;
        while (ptr->next != NULL)
        {
            ptr2 = ptr->next;
            if (ptr->data > ptr2->data)
            {
                temp = ptr->data;
                ptr->data = ptr2->data;
                ptr2->data = temp;
                swap = 1;
            }
            ptr = ptr->next;
        }
        if (!swap)
            break;
    } while (1);

    return head1;
}

Node *concat(Node *head1, Node *head2)
{
    Node *temp;
    if (head1 == NULL)
        return head2;
    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

void display(Node *head1)
{
    Node *temp = head1;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch, data;
    Node *head2 = NULL;

    printf("MENU\n1.Insert\n2.Reverse\n3.Sort\n4.Concat\n5.Display\n6.Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            insert_beg(data);
            break;

        case 2:
            head = reverse(head);
            break;

        case 3:
            head = sort(head);
            break;

        case 4:
            printf("Enter elements for second list (-1 to stop):\n");
            while (1)
            {
                scanf("%d", &data);
                if (data == -1)
                    break;
                Node *newnode = create(data);
                if (head2 == NULL)
                    head2 = newnode;
                else
                {
                    Node *t = head2;
                    while (t->next != NULL)
                        t = t->next;
                    t->next = newnode;
                }
            }
            head = concat(head, head2);
            head2 = NULL;
            break;

        case 5:
            display(head);
            break;

        case 6:
            return 0;

        default:
            printf("Invalid input\n");
        }
    }
}


**/
