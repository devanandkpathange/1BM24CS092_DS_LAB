/**
#include <stdio.h>
#include <ctype.h>

#define SIZE 50

void push(char c);
char pop();
int precedence(char c);

char stack[SIZE];
int top = -1;

int main()
{
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;

    printf("Enter expression without spaces: ");
    gets(infix);

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
        {
            push(ch);
        }
        else if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else
        {
            if (ch == ')')
            {
                while (stack[top] != '(')
                {
                    postfix[k++] = pop();
                }
                pop();
            }
            else
            {
                while (top != -1 && precedence(ch) <= precedence(stack[top]))
                {
                    postfix[k++] = pop();
                }
                push(ch);
            }
        }
    }

    while (top != -1)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix expression is: %s\n", postfix);

    return 0;
}

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if (c == '^')
        return 4;
    else if (c == '*' || c == '/' || c == '%')
        return 3;
    else if (c == '+' || c == '-')
        return 2;
    else
        return 1;
}
**/
