/**#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL;

Node *create(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
        return NULL;
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void insert_end(int value)
{
    Node *newnode = create(value);
    Node *temp;

    if (newnode == NULL)
        return;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void insert_left_position(int value, int pos)
{
    Node *temp = head;
    int i = 1;

    if (pos < 1)
    {
        printf("Insertion not possible\n");
        return;
    }

    if (pos == 1)
    {
        Node *newnode = create(value);
        if (newnode == NULL)
            return;
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
        return;
    }

    while (temp != NULL && i < pos)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Insertion not possible\n");
        return;
    }

    Node *newnode = create(value);
    if (newnode == NULL)
        return;

    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev->next = newnode;
    temp->prev = newnode;
}

void delete_value(int value)
{
    Node *temp = head;

    if (head == NULL)
    {
        printf("Deletion not possible\n");
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Deletion not possible\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display()
{
    Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch, value, pos;
    printf("\n1.Create\n2.Insert left of position\n3.Delete by value\n4.Display\n5.Exit\n");
    while (1)
    {

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_end(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert_left_position(value, pos);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            delete_value(value);
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
**/
