/**#include <stdio.h>

#define MAX 50

int queue[MAX];
int f = -1;
int r = -1;

void enqueue();
void dequeue();
void display();

void main()
{
    int choice;

    printf("Choices: 1.Insert 2.Delete 3.Display 4.Exit\n");

    while (1)
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice\n");
        }
    }
}

void enqueue()
{
    int item;

    if (r == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (f == -1)
            f = 0;

        printf("Enter element: ");
        scanf("%d", &item);

        r = r + 1;
        queue[r] = item;
    }
}

void dequeue()
{
    if (f == -1 || f > r)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Deleted element is: %d\n", queue[f]);
        f = f + 1;
    }
}

void display()
{
    int i;

    if (f == -1 || f > r)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Queue is:\n");
        for (i = f; i <= r; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
**/
