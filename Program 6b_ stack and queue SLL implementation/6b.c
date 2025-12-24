/**
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *stack_top = NULL;
struct node *queue_front = NULL;
struct node *queue_rear = NULL;

void push(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = value;
    newnode->next = stack_top;
    stack_top = newnode;
    printf("%d pushed to stack\n", value);
}

int pop()
{
    if (stack_top == NULL)
    {
        printf("Stack underflow\n");
        return -1;
    }
    struct node *temp = stack_top;
    int val = temp->data;
    stack_top = stack_top->next;
    free(temp);
    printf("%d popped from stack\n", val);
    return val;
}

int peek_stack()
{
    if (stack_top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack_top->data;
}

void display_stack()
{
    if (stack_top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *current = stack_top;
    printf("Stack elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void enqueue(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (queue_front == NULL)
    {
        queue_front = queue_rear = newnode;
    }
    else
    {
        queue_rear->next = newnode;
        queue_rear = newnode;
    }
    printf("%d enqueued to queue\n", value);
}

int dequeue()
{
    if (queue_front == NULL)
    {
        printf("Queue underflow\n");
        return -1;
    }
    struct node *temp = queue_front;
    int value = temp->data;
    queue_front = queue_front->next;
    if (queue_front == NULL)
        queue_rear = NULL;
    free(temp);
    printf("%d dequeued from queue\n", value);
    return value;
}

int peek_queue()
{
    if (queue_front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue_front->data;
}

void display_queue()
{
    if (queue_front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct node *current = queue_front;
    printf("Queue elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int option, val;

    printf("MENU\n");
    printf("1.Push an element\n");
    printf("2.Pop an element\n");
    printf("3.Peek stack element\n");
    printf("4.Display the stack\n");
    printf("5.Enqueue an element\n");
    printf("6.Dequeue an element\n");
    printf("7.Peek queue\n");
    printf("8.Display the queue\n");
    printf("9.Exit\n");

    do
    {
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the number to be inserted into stack: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            val = peek_stack();
            if (val != -1)
                printf("The top element is %d\n", val);
            break;

        case 4:
            display_stack();
            break;

        case 5:
            printf("Enter the number to be inserted in the queue: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 6:
            dequeue();
            break;

        case 7:
            val = peek_queue();
            if (val != -1)
                printf("The front element is %d\n", val);
            break;

        case 8:
            display_queue();
            break;

        case 9:
            break;

        default:
            printf("Invalid option\n");
        }
    } while (option != 9);

    return 0;
}

**/
