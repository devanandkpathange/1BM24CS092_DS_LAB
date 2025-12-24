/**#include <stdio.h>

#define MAX 50

int queue[MAX];
int f = -1;
int r = -1;

void enqueue();
void dequeue();
void display();

void enqueue()
{
    int item;

    if ((f == 0 && r == MAX - 1) || (f == r + 1))
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (f == -1)
            f = 0;

        printf("Enter element: ");
        scanf("%d", &item);

        r = (r + 1) % MAX;
        queue[r] = item;

        printf("Inserted element: %d\n", item);
    }
}

void dequeue()
{
    if (f == -1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Deleted element is: %d\n", queue[f]);

        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f + 1) % MAX;
        }
    }
}

void display()
{
    int i;

    if (f == -1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Queue is:\n");

        i = f;
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == r)
                break;
            i = (i + 1) % MAX;
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    printf("Choices\n1.Insert an element\n2.Delete an element\n3.Display queue\n4.Exit\n");

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
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
**/
