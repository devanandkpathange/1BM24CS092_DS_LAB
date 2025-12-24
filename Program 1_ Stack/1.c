/**#include <stdio.h>
#define SIZE 10

void push(char a);
void pop();
void display();
void peek();

char stack[SIZE];
int top = -1;

void push(char a)
{
    if (top == SIZE - 1)
    {
        printf("The stack is full.\nCannot add more elements.\nOverflow.\n");
    }
    else
    {
        top++;
        stack[top] = a;
        printf("Insertion successful!\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("The stack is empty.\nUnderflow.\nCannot pop.\n");
    }
    else
    {
        printf("Deleted element is: %c\n", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("The stack is empty.\nUnderflow.\nCannot peek.\n");
    }
    else
    {
        printf("Top element is: %c\n", stack[top]);
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("The stack is empty.\nUnderflow.\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%c\n", stack[i]);
        }
    }
}

int main()
{
    int choice;
    char value;

    printf("***** Menu *****\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to be inserted: ");
            scanf(" %c", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            printf("Wrong selection! Try again!\n");
        }
    }
}
**/
